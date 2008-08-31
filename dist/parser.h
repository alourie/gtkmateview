
#ifndef __PARSER_H__
#define __PARSER_H__

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gee/arraylist.h>
#include "theme.h"
#include "range_set.h"
#include "onig_wrap.h"
#include "grammar.h"

G_BEGIN_DECLS


#define GTK_MATE_TYPE_TEXT_LOC (gtk_mate_text_loc_get_type ())
#define GTK_MATE_TEXT_LOC(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_MATE_TYPE_TEXT_LOC, GtkMateTextLoc))
#define GTK_MATE_TEXT_LOC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_MATE_TYPE_TEXT_LOC, GtkMateTextLocClass))
#define GTK_MATE_IS_TEXT_LOC(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_MATE_TYPE_TEXT_LOC))
#define GTK_MATE_IS_TEXT_LOC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_MATE_TYPE_TEXT_LOC))
#define GTK_MATE_TEXT_LOC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_MATE_TYPE_TEXT_LOC, GtkMateTextLocClass))

typedef struct _GtkMateTextLocPrivate GtkMateTextLocPrivate;

#define GTK_MATE_TYPE_PARSER (gtk_mate_parser_get_type ())
#define GTK_MATE_PARSER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_MATE_TYPE_PARSER, GtkMateParser))
#define GTK_MATE_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_MATE_TYPE_PARSER, GtkMateParserClass))
#define GTK_MATE_IS_PARSER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_MATE_TYPE_PARSER))
#define GTK_MATE_IS_PARSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_MATE_TYPE_PARSER))
#define GTK_MATE_PARSER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_MATE_TYPE_PARSER, GtkMateParserClass))

typedef struct _GtkMateParserPrivate GtkMateParserPrivate;

struct _GtkMateTextLoc {
	GtkObject parent_instance;
	GtkMateTextLocPrivate * priv;
	gint line;
	gint line_offset;
};

struct _GtkMateTextLocClass {
	GtkObjectClass parent_class;
};

struct _GtkMateParser {
	GtkObject parent_instance;
	GtkMateParserPrivate * priv;
	GtkMateScope* root;
	RangeSet* changes;
	gint deactivation_level;
};

struct _GtkMateParserClass {
	GtkObjectClass parent_class;
};


GtkMateTextLoc* gtk_mate_text_loc_make (gint l, gint lo);
gboolean gtk_mate_text_loc_equal (GtkMateTextLoc* t1, GtkMateTextLoc* t2);
gboolean gtk_mate_text_loc_gt (GtkMateTextLoc* t1, GtkMateTextLoc* t2);
gboolean gtk_mate_text_loc_lt (GtkMateTextLoc* t1, GtkMateTextLoc* t2);
gboolean gtk_mate_text_loc_gte (GtkMateTextLoc* t1, GtkMateTextLoc* t2);
gboolean gtk_mate_text_loc_lte (GtkMateTextLoc* t1, GtkMateTextLoc* t2);
char* gtk_mate_text_loc_to_s (GtkMateTextLoc* self);
GtkMateTextLoc* gtk_mate_text_loc_new (void);
GType gtk_mate_text_loc_get_type (void);
extern GtkMateParser* gtk_mate_parser_current;
void gtk_mate_parser_make_root (GtkMateParser* self);
void gtk_mate_parser_stop_parsing (GtkMateParser* self);
void gtk_mate_parser_start_parsing (GtkMateParser* self);
gboolean gtk_mate_parser_is_parsing (GtkMateParser* self);
void gtk_mate_parser_clear_line (GtkMateParser* self, gint line_ix, GtkMateScope* start_scope, GeeArrayList* all_scopes, GeeArrayList* closed_scopes);
GtkMateScope* gtk_mate_parser_get_expected_scope (GtkMateParser* self, GtkMateScope* current_scope, gint line, gint line_offset);
void gtk_mate_parser_close_scope (GtkMateParser* self, GtkMateScanner* scanner, GtkMateScope* expected_scope, gint line_ix, const char* line, GtkMateMarker* m, GeeArrayList* all_scopes, GeeArrayList* closed_scopes);
void gtk_mate_parser_open_scope (GtkMateParser* self, GtkMateScanner* scanner, GtkMateScope* expected_scope, gint line_ix, const char* line, gint length, GtkMateMarker* m, GeeArrayList* all_scopes, GeeArrayList* closed_scopes);
void gtk_mate_parser_single_scope (GtkMateParser* self, GtkMateScanner* scanner, GtkMateScope* expected_scope, gint line_ix, const char* line, gint length, GtkMateMarker* m, GeeArrayList* all_scopes, GeeArrayList* closed_scopes);
void gtk_mate_parser_handle_captures (GtkMateParser* self, gint line_ix, const char* line, GtkMateScope* scope, GtkMateMarker* m, GeeArrayList* all_scopes, GeeArrayList* closed_scopes);
OnigurumaRegex* gtk_mate_parser_make_closing_regex (GtkMateParser* self, const char* line, GtkMateScope* scope, GtkMateMarker* m);
void gtk_mate_parser_collect_child_captures (GtkMateParser* self, gint line_ix, GtkMateScope* scope, GtkMateMarker* m, GeeArrayList* all_scopes, GeeArrayList* closed_scopes);
void gtk_mate_parser_connect_buffer_signals (GtkMateParser* self);
void gtk_mate_parser_insert_text_handler (GtkMateParser* self, GtkMateBuffer* bf, GtkTextIter* pos, const char* text, gint length);
void gtk_mate_parser_delete_range_handler (GtkMateParser* self, GtkMateBuffer* bf, GtkTextIter* pos, GtkTextIter* pos2);
void gtk_mate_parser_insert_text_after_handler (GtkMateParser* self, GtkMateBuffer* bf, GtkTextIter* pos, const char* text, gint length);
void gtk_mate_parser_delete_range_after_handler (GtkMateParser* self, GtkMateBuffer* bf, GtkTextIter* pos, GtkTextIter* pos2);
void gtk_mate_parser_static_insert_text_after_handler (GtkMateBuffer* bf, GtkTextIter* pos, const char* text, gint length);
void gtk_mate_parser_static_delete_range_after_handler (GtkMateBuffer* bf, GtkTextIter* pos, GtkTextIter* pos2);
GtkMateParser* gtk_mate_parser_create (GtkMateGrammar* grammar, GtkMateBuffer* buffer);
GtkMateParser* gtk_mate_parser_new (void);
GtkMateGrammar* gtk_mate_parser_get_grammar (GtkMateParser* self);
void gtk_mate_parser_set_grammar (GtkMateParser* self, GtkMateGrammar* value);
GtkMateColourer* gtk_mate_parser_get_colourer (GtkMateParser* self);
void gtk_mate_parser_set_colourer (GtkMateParser* self, GtkMateColourer* value);
GtkMateBuffer* gtk_mate_parser_get_buffer (GtkMateParser* self);
void gtk_mate_parser_set_buffer (GtkMateParser* self, GtkMateBuffer* value);
GType gtk_mate_parser_get_type (void);


G_END_DECLS

#endif