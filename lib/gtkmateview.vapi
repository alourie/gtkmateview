/* gtkmateview.vapi generated by valac, do not modify. */

[CCode (cprefix = "Gtk", lower_case_cprefix = "gtk_")]
namespace Gtk {
	[CCode (cprefix = "GtkMate", lower_case_cprefix = "gtk_mate_")]
	namespace Mate {
		[CCode (cheader_filename = "buffer.h")]
		public class Buffer : Gtk.SourceBuffer {
			public static Gee.ArrayList<Gtk.Mate.Bundle> bundles;
			public Gtk.Mate.Parser parser;
			public static Gee.ArrayList<Gtk.Mate.Theme> themes;
			public Gee.ArrayList<int> current_scope_range ();
			public Gtk.TextIter cursor_iter ();
			public int cursor_line ();
			public int cursor_line_offset ();
			public Gtk.TextMark cursor_mark ();
			public int cursor_offset ();
			public Gtk.TextIter end_iter ();
			public Gtk.TextMark end_mark ();
			public string? get_line (int line);
			public string? get_line1 (int line_ix);
			public int get_line_length (int line);
			public Gtk.TextIter iter_ (int offset);
			public Gtk.TextIter iter_at_line_index (int line, int line_offset);
			public Gtk.TextIter iter_at_line_offset (int line, int line_offset);
			public Gtk.TextIter iter_from_mark (Gtk.TextMark mark);
			public Gtk.TextIter line_end_iter (int line);
			public Gtk.TextIter line_end_iter1 (int line);
			public Gtk.TextIter line_start_iter (int line);
			public Buffer ();
			public void select_current_scope ();
			public Gtk.TextMark selection_mark ();
			public string? set_grammar_by_filename (string filename);
			public string? set_grammar_by_first_line (string first_line);
			public bool set_grammar_by_name (string name);
			public Gtk.TextIter start_iter ();
			public Gtk.TextMark start_mark ();
			public signal void grammar_changed (string name);
		}
		[CCode (cheader_filename = "bundle.h")]
		public class Bundle : Gtk.Object {
			public Gee.ArrayList<Gtk.Mate.Grammar> grammars;
			public Bundle (string name);
			public string name { get; set; }
		}
		[CCode (cheader_filename = "colourer.h")]
		public class Colourer : Gtk.Object {
			public static int char_to_hex (unichar ch);
			public void colour_line_with_scopes (Gee.ArrayList<Gtk.Mate.Scope> scopes);
			public void colour_scope (Gtk.Mate.Scope scope, bool inner, bool force = true);
			public string? global_background_colour ();
			public string? global_foreground_colour ();
			public static int hex_to_int (unichar ch1, unichar ch2);
			public static string? merge_colour (string? parent_colour, string colour);
			public Colourer (Gtk.Mate.Buffer buffer);
			public Gdk.Color parse_colour (string colour);
			public void set_global_settings (Gtk.Mate.View view);
			public void set_tag_properties (Gtk.Mate.Scope scope, Gtk.TextTag tag, Gtk.Mate.ThemeSetting setting);
			public void uncolour_scope (Gtk.Mate.Scope scope, bool recurse);
			public void uncolour_scopes (Gee.ArrayList<Gtk.Mate.Scope> scopes);
			public Gtk.Mate.Buffer buffer { get; set; }
			public Gtk.Mate.Theme theme { get; set; }
		}
		[CCode (cheader_filename = "pattern.h")]
		public class DoublePattern : Gtk.Mate.Pattern {
			public Onig.Rx begin;
			public Gee.HashMap<int,string> begin_captures;
			public string begin_string;
			public Gee.HashMap<int,string> both_captures;
			public string content_name;
			public Onig.Rx end;
			public Gee.HashMap<int,string> end_captures;
			public string end_string;
			public Gee.ArrayList<Gtk.Mate.Pattern> patterns;
			public static Gtk.Mate.DoublePattern? create_from_plist (Gee.ArrayList<Gtk.Mate.Pattern> all_patterns, PList.Dict pd);
			public DoublePattern ();
		}
		[CCode (cheader_filename = "exporter.h")]
		public class Exporter : Gtk.Object {
			public Gtk.Mate.View view;
			public Exporter (Gtk.Mate.View v);
			public string to_html (string title);
		}
		[CCode (cheader_filename = "grammar.h")]
		public class Grammar : Gtk.Object {
			public Gee.ArrayList<Gtk.Mate.Pattern> all_patterns;
			public string comment;
			public string[] file_types;
			public Onig.Rx first_line_match;
			public Onig.Rx folding_start_marker;
			public Onig.Rx folding_stop_marker;
			public string key_equivalent;
			public bool loaded;
			public Gee.ArrayList<Gtk.Mate.Pattern> patterns;
			public Gee.HashMap<string,Gee.ArrayList<Gtk.Mate.Pattern>> repository;
			public string scope_name;
			public static Gtk.Mate.Grammar? find_by_scope_name (string scope);
			public void init_for_reference ();
			public void init_for_use ();
			public Grammar (PList.Dict plist);
			public string filename { get; set; }
			public string name { get; set; }
			public PList.Dict plist { get; set; }
		}
		[CCode (cheader_filename = "pattern.h")]
		public class IncludePattern : Gtk.Mate.Pattern {
			public static Gtk.Mate.IncludePattern? create_from_plist (PList.Dict pd);
			public IncludePattern ();
		}
		[CCode (cheader_filename = "scanner.h")]
		public class Marker : Gtk.Object {
			public int from;
			public int hint;
			public bool is_close_scope;
			public Onig.Match match;
			public Gtk.Mate.Pattern pattern;
			public Marker ();
		}
		[CCode (cheader_filename = "matcher.h")]
		public class Matcher : Gtk.Object {
			public Gee.ArrayList<Onig.Rx> neg_rxs;
			public Onig.Rx pos_rx;
			public static int compare_match (string scope_string, Onig.Match m1, Onig.Match m2);
			public static Gee.ArrayList<Gtk.Mate.Matcher> compile (string selector_string);
			public static Onig.Match get_match (string selector_string, string scope_string);
			public static bool match (string selector_string, string scope_string, out Onig.Match match);
			public Matcher ();
			public static bool test_match (string selector_string, string scope_string);
			public static bool test_match_re (Onig.Rx positive_selector_regex, Gee.ArrayList<Onig.Rx> negative_selector_regex, string scope_string, out Onig.Match match);
			public static string test_rank (string selector_a, string selector_b, string scope_string);
		}
		[CCode (cheader_filename = "parser.h")]
		public class Parser : Gtk.Object {
			public bool always_parse_all;
			public RangeSet changes;
			public int deactivation_level;
			public Gtk.TextTag dummy_tag;
			public Gtk.TextTag dummy_tag2;
			public static Gee.ArrayList<Gtk.Mate.Parser> existing_parsers;
			public int last_visible_line;
			public int parsed_upto;
			public Gtk.Mate.Scope root;
			public GLib.Sequence<Gtk.TextTag> tags;
			public void added_tag (Gtk.TextTag tag);
			public void change_theme (Gtk.Mate.Theme theme);
			public void clear_line (int line_ix, Gtk.Mate.Scope start_scope, Gee.ArrayList<Gtk.Mate.Scope> all_scopes, Gee.ArrayList<Gtk.Mate.Scope> closed_scopes, Gee.ArrayList<Gtk.Mate.Scope> removed_scopes);
			public void close ();
			public void close_scope (Gtk.Mate.Scanner scanner, Gtk.Mate.Scope? expected_scope, int line_ix, string line, int length, Gtk.Mate.Marker m, Gee.ArrayList<Gtk.Mate.Scope> all_scopes, Gee.ArrayList<Gtk.Mate.Scope> closed_scopes, Gee.ArrayList<Gtk.Mate.Scope> removed_scopes);
			public void collect_child_captures (int line_ix, int length, Gtk.Mate.Scope scope, Gtk.Mate.Marker m, Gee.ArrayList<Gtk.Mate.Scope> all_scopes, Gee.ArrayList<Gtk.Mate.Scope> closed_scopes);
			public void connect_buffer_signals ();
			public static Gtk.Mate.Parser create (Gtk.Mate.Grammar grammar, Gtk.Mate.Buffer buffer);
			public void delete_range_after_handler (Gtk.Mate.Buffer bf, Gtk.TextIter pos, Gtk.TextIter pos2);
			public void delete_range_handler (Gtk.Mate.Buffer bf, Gtk.TextIter pos, Gtk.TextIter pos2);
			public Gtk.Mate.Scope? get_expected_scope (Gtk.Mate.Scope current_scope, int line, int line_offset);
			public void handle_captures (int line_ix, int length, string line, Gtk.Mate.Scope scope, Gtk.Mate.Marker m, Gee.ArrayList<Gtk.Mate.Scope> all_scopes, Gee.ArrayList<Gtk.Mate.Scope> closed_scopes);
			public void insert_text_after_handler (Gtk.Mate.Buffer bf, Gtk.TextIter pos, string text, int length);
			public void insert_text_handler (Gtk.Mate.Buffer bf, Gtk.TextIter pos, string text, int length);
			public bool is_parsing ();
			public int last_line_parsed ();
			public void last_visible_line_changed (int new_last_visible_line);
			public Onig.Rx? make_closing_regex (string line, Gtk.Mate.Scope scope, Gtk.Mate.Marker m);
			public void make_root ();
			public Parser ();
			public void open_scope (Gtk.Mate.Scanner scanner, Gtk.Mate.Scope? expected_scope, int line_ix, string line, int length, Gtk.Mate.Marker m, Gee.ArrayList<Gtk.Mate.Scope> all_scopes, Gee.ArrayList<Gtk.Mate.Scope> closed_scopes, Gee.ArrayList<Gtk.Mate.Scope> removed_scopes);
			public void recolour_children (Gtk.Mate.Scope scope);
			public void remove_tags ();
			public void reset_table_priorities ();
			public void set_end_mark_safely (Gtk.Mate.Scope scope, Gtk.Mate.Marker m, int line_ix, int length, int cap);
			public void set_inner_end_mark_safely (Gtk.Mate.Scope scope, Gtk.Mate.Marker m, int line_ix, int length, int cap);
			public void set_inner_start_mark_safely (Gtk.Mate.Scope scope, Gtk.Mate.Marker m, int line_ix, int length, int cap);
			public void set_start_mark_safely (Gtk.Mate.Scope scope, Gtk.Mate.Marker m, int line_ix, int length, int cap);
			public void single_scope (Gtk.Mate.Scanner scanner, Gtk.Mate.Scope? expected_scope, int line_ix, string line, int length, Gtk.Mate.Marker m, Gee.ArrayList<Gtk.Mate.Scope> all_scopes, Gee.ArrayList<Gtk.Mate.Scope> closed_scopes, Gee.ArrayList<Gtk.Mate.Scope> removed_scopes);
			public void start_parsing ();
			public static void static_delete_range_after_handler (Gtk.Mate.Buffer bf, Gtk.TextIter pos, Gtk.TextIter pos2);
			public static void static_insert_text_after_handler (Gtk.Mate.Buffer bf, Gtk.TextIter pos, string text, int length);
			public void stop_parsing ();
			public static int tag_compare (Gtk.TextTag tag1, Gtk.TextTag tag2, void* data);
			public Gtk.Mate.Buffer buffer { get; set; }
			public Gtk.Mate.Colourer colourer { get; set; }
			public Gtk.Mate.Grammar grammar { get; set; }
			public int look_ahead { get; set; }
		}
		[CCode (cheader_filename = "pattern.h")]
		public class Pattern : Gtk.Object {
			public static Gee.ArrayList<Gtk.Mate.Pattern> all_patterns;
			public string comment;
			public bool disabled;
			public string name;
			public static Gtk.Mate.Pattern? create_from_plist (Gee.ArrayList<Gtk.Mate.Pattern> all_patterns, PList.Dict pd);
			public static Gee.HashMap<int,string> make_captures_from_plist (PList.Dict? pd);
			public Pattern ();
			public static void replace_base_and_self_includes (Gee.ArrayList<Gtk.Mate.Pattern> patlist, Gtk.Mate.Grammar g);
			public static void replace_include_patterns (Gee.ArrayList<Gtk.Mate.Pattern> patlist, Gtk.Mate.Grammar g);
			public static void replace_repository_includes (Gee.ArrayList<Gtk.Mate.Pattern> patlist, Gtk.Mate.Grammar g);
			public Gtk.Mate.Grammar grammar { get; set; }
		}
		[CCode (cheader_filename = "scanner.h")]
		public class Scanner : Gtk.Object, Gee.Iterable<Gtk.Mate.Marker> {
			[CCode (cheader_filename = "scanner.h")]
			public class Iterator<Marker> : Gtk.Object, Gee.Iterator<Marker> {
				public Marker next_marker;
				public Iterator (Gtk.Mate.Scanner s);
				public Gtk.Mate.Scanner scanner { get; set construct; }
			}
			public Gee.ArrayList<Gtk.Mate.Marker> cached_markers;
			public int position;
			public Gtk.Mate.Marker? find_next_marker ();
			public Gtk.Mate.Marker? get_cached_marker ();
			public Scanner (Gtk.Mate.Scope s, string line, int line_length);
			public void remove_preceding_cached_markers (Gtk.Mate.Marker m);
			public Onig.Match? scan_for_match (int from, Gtk.Mate.Pattern p);
			public Gtk.Mate.Scope current_scope { get; set; }
			public string line { get; set; }
			public int line_length { get; set; }
		}
		[CCode (cheader_filename = "scope.h")]
		public class Scope : Gtk.Object {
			public string begin_match_string;
			public string bg_colour;
			public Onig.Match close_match;
			public Onig.Rx closing_regex;
			public Gtk.Mate.TextLoc dummy_end_loc;
			public Gtk.Mate.TextLoc dummy_start_loc;
			public Gtk.TextMark end_mark;
			public string end_match_string;
			public string fg_colour;
			public int indent;
			public Gtk.TextMark inner_end_mark;
			public Gtk.TextMark inner_start_mark;
			public Gtk.TextTag inner_tag;
			public bool is_capture;
			public bool is_open;
			public Onig.Match open_match;
			public Gtk.Mate.Scope parent;
			public Gtk.Mate.Pattern pattern;
			public GLib.StringBuilder pretty_string;
			public static int scope_count;
			public Gtk.TextMark start_mark;
			public Gtk.TextTag tag;
			public Gtk.Mate.ThemeSetting theme_setting;
			public void add_child (Gtk.Mate.Scope s);
			public void clear_after (int line_ix, int line_offset);
			public static int compare (Gtk.Mate.Scope a, Gtk.Mate.Scope b, void* data);
			public static int compare_by_loc (Gtk.Mate.Scope a, Gtk.Mate.Scope b, void* data);
			public Gtk.Mate.Scope containing_double_scope (int line_ix);
			public bool contains_loc (Gtk.Mate.TextLoc loc);
			public Gee.ArrayList<Gtk.Mate.Scope> delete_any_on_line_not_in (int line_ix, Gee.ArrayList<Gtk.Mate.Scope> scopes);
			public void delete_child (Gtk.Mate.Scope s);
			public Gtk.TextIter end_iter ();
			public int end_line ();
			public int end_line_offset ();
			public Gtk.Mate.TextLoc end_loc ();
			public void end_mark_set (int line, int line_offset, bool has_left_gravity);
			public int end_offset ();
			public Gtk.Mate.Scope? first_child_after (Gtk.Mate.TextLoc loc);
			public string hierarchy_names (bool inner);
			public Gtk.TextIter inner_end_iter ();
			public int inner_end_line ();
			public int inner_end_line_offset ();
			public Gtk.Mate.TextLoc inner_end_loc ();
			public void inner_end_mark_set (int line, int line_offset, bool has_left_gravity);
			public int inner_end_offset ();
			public Gtk.TextIter inner_start_iter ();
			public int inner_start_line ();
			public int inner_start_line_offset ();
			public Gtk.Mate.TextLoc inner_start_loc ();
			public void inner_start_mark_set (int line, int line_offset, bool has_left_gravity);
			public int inner_start_offset ();
			public bool is_root ();
			public string? nearest_background_colour ();
			public string? nearest_background_colour1 ();
			public string? nearest_foreground_colour ();
			public string? nearest_foreground_colour1 ();
			public Scope (Gtk.Mate.Buffer buf, string? name);
			public bool overlaps_with (Gtk.Mate.Scope other);
			public string pretty (int indent);
			public int priority (bool inner);
			public Gtk.Mate.Scope root ();
			public Gtk.Mate.Scope? scope_at (int line, int line_offset);
			public Gtk.TextIter start_iter ();
			public int start_line ();
			public int start_line_offset ();
			public Gtk.Mate.TextLoc start_loc ();
			public void start_mark_set (int line, int line_offset, bool has_left_gravity);
			public int start_offset ();
			public bool surface_identical_to (Gtk.Mate.Scope other);
			public bool surface_identical_to_modulo_ending (Gtk.Mate.Scope other);
			public Gtk.Mate.Buffer buffer { get; set; }
			public GLib.Sequence<Gtk.Mate.Scope> children { get; }
			public bool is_coloured { get; set; }
			public string? name { get; set; }
		}
		[CCode (cheader_filename = "pattern.h")]
		public class SinglePattern : Gtk.Mate.Pattern {
			public Gee.HashMap<int,string> captures;
			public Onig.Rx match;
			public static Gtk.Mate.SinglePattern? create_from_plist (Gee.ArrayList<Gtk.Mate.Pattern> all_patterns, PList.Dict pd);
			public SinglePattern ();
		}
		[CCode (cheader_filename = "parser.h")]
		public class TextLoc : Gtk.Object {
			public int line;
			public int line_offset;
			public static bool equal (Gtk.Mate.TextLoc t1, Gtk.Mate.TextLoc t2);
			public static bool gt (Gtk.Mate.TextLoc t1, Gtk.Mate.TextLoc t2);
			public static bool gte (Gtk.Mate.TextLoc t1, Gtk.Mate.TextLoc t2);
			public static bool lt (Gtk.Mate.TextLoc t1, Gtk.Mate.TextLoc t2);
			public static bool lte (Gtk.Mate.TextLoc t1, Gtk.Mate.TextLoc t2);
			public static Gtk.Mate.TextLoc make (int l, int lo);
			public TextLoc ();
			public string to_s ();
		}
		[CCode (cheader_filename = "theme.h")]
		public class Theme : Gtk.Object {
			public static Gee.ArrayList<Gtk.Mate.Theme> _themes;
			public string author;
			public Gee.HashMap<string,Gtk.Mate.ThemeSetting> cached_setting_for_scopes;
			public Gee.HashMap<string,string> global_settings;
			public bool is_initialized;
			public string name;
			public Gee.ArrayList<Gtk.Mate.ThemeSetting> settings;
			public static Gtk.Mate.Theme create_from_plist (PList.Dict dict);
			public void init_for_use ();
			public Theme ();
			public Gtk.Mate.ThemeSetting settings_for_scope (Gtk.Mate.Scope scope, bool inner, Gtk.Mate.ThemeSetting? exclude_setting);
			public static Gee.ArrayList<string>? theme_filenames ();
			public static Gee.ArrayList<Gtk.Mate.Theme> themes ();
		}
		[CCode (cheader_filename = "theme.h")]
		public class ThemeSetting : Gtk.Object {
			public Gee.ArrayList<Gtk.Mate.Matcher> matchers;
			public string name;
			public string selector;
			public Gee.HashMap<string,string> settings;
			public void compile_scope_matchers ();
			public static Gtk.Mate.ThemeSetting create_from_plist (PList.Dict dict);
			public bool match (string scope, out Onig.Match match);
			public ThemeSetting ();
		}
		[CCode (cheader_filename = "view.h")]
		public class View : Gtk.SourceView {
			public int first_visible_line ();
			public Gtk.Mate.Parser? get_parser ();
			public int last_visible_line ();
			public View ();
			public void set_global_theme_settings ();
			public bool set_theme_by_name (string name);
			public void value_changed_handler ();
		}
		[CCode (cheader_filename = "gtkmateview.h")]
		public static string textmate_dir;
		[CCode (cheader_filename = "gtkmateview.h")]
		public static Gee.ArrayList<string>? bundle_dirs ();
		[CCode (cheader_filename = "gtkmateview.h")]
		public static int load_bundles ();
		[CCode (cheader_filename = "gtkmateview.h")]
		public static void load_themes ();
		[CCode (cheader_filename = "gtkmateview.h")]
		public static string? textmate_share_dir ();
	}
}
[CCode (cprefix = "Onig", lower_case_cprefix = "onig_")]
namespace Onig {
	[CCode (cheader_filename = "onig_wrap.h")]
	public class Match : GLib.Object {
		public static int count;
		public string text;
		public int begin (int capture);
		public int end (int capture);
		public Match ();
		public int num_captures ();
		public Oniguruma.Region rg { get; set; }
		public Oniguruma.RegexT rx { get; set; }
	}
	[CCode (cheader_filename = "onig_wrap.h")]
	public class OnigError : GLib.Object {
		public int code;
		public Oniguruma.OnigErrorInfo error_info;
		public OnigError ();
	}
	[CCode (cheader_filename = "onig_wrap.h")]
	public class Rx : GLib.Object {
		public bool matches_start_of_line;
		public static Onig.Rx? make (string pattern, Oniguruma.OnigOptionType* options, out Onig.OnigError error);
		public static Onig.Rx? make1 (string pattern);
		public Rx ();
		public Onig.Match? search (string target, int start, int end);
		public Oniguruma.RegexT rx { get; set; }
	}
}
[CCode (cprefix = "PList", lower_case_cprefix = "plist_")]
namespace PList {
	[CCode (cheader_filename = "plist.h")]
	public class Array : PList.Node {
		public Gee.ArrayList<PList.Node> array;
		public PList.Node get (int ix);
		public Array ();
		public static PList.Array parse_array (Xml.Node* node);
	}
	[CCode (cheader_filename = "plist.h")]
	public class Dict : PList.Node {
		public Gee.HashMap<string,PList.Node> map;
		public PList.Node get (string key);
		public string[] keys ();
		public Dict ();
		public static PList.Dict parse_dict (Xml.Node* node);
		public void print_keys ();
	}
	[CCode (cheader_filename = "plist.h")]
	public class Integer : PList.Node {
		public int value;
		public Integer ();
	}
	[CCode (cheader_filename = "plist.h")]
	public class Node : GLib.Object {
		public Node ();
		public static PList.Node? parse_xml_node (Xml.Node* node);
	}
	[CCode (cheader_filename = "plist.h")]
	public class String : PList.Node {
		public string str;
		public String ();
	}
	[CCode (cheader_filename = "plist.h")]
	public static PList.Dict? parse (string filename) throws GLib.FileError;
	[CCode (cheader_filename = "plist.h")]
	public static void print_plist (int indent, PList.Node node);
}
[CCode (cprefix = "XML_ERROR_", cheader_filename = "plist.h")]
public errordomain XmlError {
	FILE_NOT_FOUND,
	XML_DOCUMENT_EMPTY,
}
[CCode (cheader_filename = "range_set.h")]
public class RangeSet : GLib.Object, Gee.Iterable<RangeSet.Range> {
	[CCode (cheader_filename = "range_set.h")]
	public class Range : GLib.Object {
		public int a;
		public int b;
		public Range ();
	}
	public Gee.ArrayList<RangeSet.Range> ranges;
	public void add (int a, int b);
	public bool is_empty ();
	public int length ();
	public int max (int a, int b);
	public void merge (int ix);
	public int min (int a, int b);
	public RangeSet ();
	public string present ();
	public int size ();
}
[CCode (cheader_filename = "string_helper.h")]
public class StringHelper : GLib.Object {
	public static string gsub (string start_string, string match_string, string replacement_string);
	public StringHelper ();
	public static Gee.ArrayList<int> occurrences (string s, string t);
}
