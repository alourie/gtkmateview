
#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gee/arraylist.h>
#include <stdlib.h>
#include <string.h>


#define GTK_MATE_TYPE_BUNDLE (gtk_mate_bundle_get_type ())
#define GTK_MATE_BUNDLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_MATE_TYPE_BUNDLE, GtkMateBundle))
#define GTK_MATE_BUNDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_MATE_TYPE_BUNDLE, GtkMateBundleClass))
#define GTK_MATE_IS_BUNDLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_MATE_TYPE_BUNDLE))
#define GTK_MATE_IS_BUNDLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_MATE_TYPE_BUNDLE))
#define GTK_MATE_BUNDLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_MATE_TYPE_BUNDLE, GtkMateBundleClass))

typedef struct _GtkMateBundle GtkMateBundle;
typedef struct _GtkMateBundleClass GtkMateBundleClass;
typedef struct _GtkMateBundlePrivate GtkMateBundlePrivate;

#define GTK_MATE_TYPE_GRAMMAR (gtk_mate_grammar_get_type ())
#define GTK_MATE_GRAMMAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_MATE_TYPE_GRAMMAR, GtkMateGrammar))
#define GTK_MATE_GRAMMAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_MATE_TYPE_GRAMMAR, GtkMateGrammarClass))
#define GTK_MATE_IS_GRAMMAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_MATE_TYPE_GRAMMAR))
#define GTK_MATE_IS_GRAMMAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_MATE_TYPE_GRAMMAR))
#define GTK_MATE_GRAMMAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_MATE_TYPE_GRAMMAR, GtkMateGrammarClass))

typedef struct _GtkMateGrammar GtkMateGrammar;
typedef struct _GtkMateGrammarClass GtkMateGrammarClass;

struct _GtkMateBundle {
	GtkObject parent_instance;
	GtkMateBundlePrivate * priv;
	GeeArrayList* grammars;
};

struct _GtkMateBundleClass {
	GtkObjectClass parent_class;
};

struct _GtkMateBundlePrivate {
	char* _name;
};



GType gtk_mate_bundle_get_type (void);
GType gtk_mate_grammar_get_type (void);
#define GTK_MATE_BUNDLE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GTK_MATE_TYPE_BUNDLE, GtkMateBundlePrivate))
enum  {
	GTK_MATE_BUNDLE_DUMMY_PROPERTY,
	GTK_MATE_BUNDLE_NAME
};
static void gtk_mate_bundle_set_name (GtkMateBundle* self, const char* value);
GtkMateBundle* gtk_mate_bundle_new (const char* name);
GtkMateBundle* gtk_mate_bundle_construct (GType object_type, const char* name);
GtkMateBundle* gtk_mate_bundle_new (const char* name);
const char* gtk_mate_bundle_get_name (GtkMateBundle* self);
static GObject * gtk_mate_bundle_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static gpointer gtk_mate_bundle_parent_class = NULL;
static void gtk_mate_bundle_finalize (GObject* obj);
static void gtk_mate_bundle_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void gtk_mate_bundle_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



GtkMateBundle* gtk_mate_bundle_construct (GType object_type, const char* name) {
	GtkMateBundle * self;
	g_return_val_if_fail (name != NULL, NULL);
	self = g_object_newv (object_type, 0, NULL);
	gtk_mate_bundle_set_name (self, name);
	return self;
}


GtkMateBundle* gtk_mate_bundle_new (const char* name) {
	return gtk_mate_bundle_construct (GTK_MATE_TYPE_BUNDLE, name);
}


const char* gtk_mate_bundle_get_name (GtkMateBundle* self) {
	g_return_val_if_fail (self != NULL, NULL);
	return self->priv->_name;
}


static void gtk_mate_bundle_set_name (GtkMateBundle* self, const char* value) {
	char* _tmp2_;
	const char* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp2_ = NULL;
	_tmp1_ = NULL;
	self->priv->_name = (_tmp2_ = (_tmp1_ = value, (_tmp1_ == NULL) ? NULL : g_strdup (_tmp1_)), self->priv->_name = (g_free (self->priv->_name), NULL), _tmp2_);
	g_object_notify ((GObject *) self, "name");
}


static GObject * gtk_mate_bundle_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GtkMateBundleClass * klass;
	GObjectClass * parent_class;
	GtkMateBundle * self;
	klass = GTK_MATE_BUNDLE_CLASS (g_type_class_peek (GTK_MATE_TYPE_BUNDLE));
	parent_class = G_OBJECT_CLASS (g_type_class_peek_parent (klass));
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = GTK_MATE_BUNDLE (obj);
	{
		GeeArrayList* _tmp0_;
		_tmp0_ = NULL;
		self->grammars = (_tmp0_ = gee_array_list_new (GTK_MATE_TYPE_GRAMMAR, (GBoxedCopyFunc) g_object_ref, g_object_unref, g_direct_equal), (self->grammars == NULL) ? NULL : (self->grammars = (g_object_unref (self->grammars), NULL)), _tmp0_);
	}
	return obj;
}


static void gtk_mate_bundle_class_init (GtkMateBundleClass * klass) {
	gtk_mate_bundle_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (GtkMateBundlePrivate));
	G_OBJECT_CLASS (klass)->get_property = gtk_mate_bundle_get_property;
	G_OBJECT_CLASS (klass)->set_property = gtk_mate_bundle_set_property;
	G_OBJECT_CLASS (klass)->constructor = gtk_mate_bundle_constructor;
	G_OBJECT_CLASS (klass)->finalize = gtk_mate_bundle_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), GTK_MATE_BUNDLE_NAME, g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void gtk_mate_bundle_instance_init (GtkMateBundle * self) {
	self->priv = GTK_MATE_BUNDLE_GET_PRIVATE (self);
}


static void gtk_mate_bundle_finalize (GObject* obj) {
	GtkMateBundle * self;
	self = GTK_MATE_BUNDLE (obj);
	self->priv->_name = (g_free (self->priv->_name), NULL);
	(self->grammars == NULL) ? NULL : (self->grammars = (g_object_unref (self->grammars), NULL));
	G_OBJECT_CLASS (gtk_mate_bundle_parent_class)->finalize (obj);
}


GType gtk_mate_bundle_get_type (void) {
	static GType gtk_mate_bundle_type_id = 0;
	if (gtk_mate_bundle_type_id == 0) {
		static const GTypeInfo g_define_type_info = { sizeof (GtkMateBundleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gtk_mate_bundle_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GtkMateBundle), 0, (GInstanceInitFunc) gtk_mate_bundle_instance_init, NULL };
		gtk_mate_bundle_type_id = g_type_register_static (GTK_TYPE_OBJECT, "GtkMateBundle", &g_define_type_info, 0);
	}
	return gtk_mate_bundle_type_id;
}


static void gtk_mate_bundle_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	GtkMateBundle * self;
	gpointer boxed;
	self = GTK_MATE_BUNDLE (object);
	switch (property_id) {
		case GTK_MATE_BUNDLE_NAME:
		g_value_set_string (value, gtk_mate_bundle_get_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void gtk_mate_bundle_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	GtkMateBundle * self;
	self = GTK_MATE_BUNDLE (object);
	switch (property_id) {
		case GTK_MATE_BUNDLE_NAME:
		gtk_mate_bundle_set_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




