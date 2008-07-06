
#include "onig_wrap.h"
#include <stdio.h>




enum  {
	ONIGURUMA_ONIG_ERROR_DUMMY_PROPERTY
};
static gpointer oniguruma_onig_error_parent_class = NULL;
static void oniguruma_onig_error_dispose (GObject * obj);
struct _OnigurumaRegexPrivate {
	regex_t* _rx;
};

#define ONIGURUMA_REGEX_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), ONIGURUMA_TYPE_REGEX, OnigurumaRegexPrivate))
enum  {
	ONIGURUMA_REGEX_DUMMY_PROPERTY,
	ONIGURUMA_REGEX_RX
};
static gpointer oniguruma_regex_parent_class = NULL;
static void oniguruma_regex_dispose (GObject * obj);



OnigurumaOnigError* oniguruma_onig_error_new (void) {
	OnigurumaOnigError * self;
	self = g_object_newv (ONIGURUMA_TYPE_ONIG_ERROR, 0, NULL);
	return self;
}


static void oniguruma_onig_error_class_init (OnigurumaOnigErrorClass * klass) {
	oniguruma_onig_error_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->dispose = oniguruma_onig_error_dispose;
}


static void oniguruma_onig_error_instance_init (OnigurumaOnigError * self) {
}


static void oniguruma_onig_error_dispose (GObject * obj) {
	OnigurumaOnigError * self;
	self = ONIGURUMA_ONIG_ERROR (obj);
	G_OBJECT_CLASS (oniguruma_onig_error_parent_class)->dispose (obj);
}


GType oniguruma_onig_error_get_type (void) {
	static GType oniguruma_onig_error_type_id = 0;
	if (G_UNLIKELY (oniguruma_onig_error_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (OnigurumaOnigErrorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) oniguruma_onig_error_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (OnigurumaOnigError), 0, (GInstanceInitFunc) oniguruma_onig_error_instance_init };
		oniguruma_onig_error_type_id = g_type_register_static (G_TYPE_OBJECT, "OnigurumaOnigError", &g_define_type_info, 0);
	}
	return oniguruma_onig_error_type_id;
}


void oniguruma_regex_search (OnigurumaRegex* self, const char* target, gint start, gint end) {
	OnigRegion* rg;
	gchar* ctarget;
	g_return_if_fail (ONIGURUMA_IS_REGEX (self));
	g_return_if_fail (target != NULL);
	rg = onig_region_new ();
	fprintf (stdout, "allocated region\n");
	ctarget = ((gchar*) (target));
	onig_search (self->priv->_rx, ctarget, (ctarget + strlen (target)), ctarget + start, (ctarget + end), rg, ONIG_OPTION_NONE);
	fprintf (stdout, "count: %d\n", rg->num_regs);
	{
		gint i;
		i = 0;
		for (; i < rg->num_regs; i++) {
			fprintf (stdout, "  %d begins at %d\n", i, rg->beg[i]);
		}
	}
	(rg == NULL ? NULL : (rg = ( (rg), NULL)));
}


OnigurumaRegex* oniguruma_regex_make (const char* pattern, OnigOptionType* options, OnigurumaOnigError** error) {
	OnigurumaRegex* rx;
	gchar* c_pattern;
	regex_t* rx1;
	OnigErrorInfo err_info = {0};
	regex_t* _tmp2;
	gint _tmp1;
	regex_t* _tmp0;
	gint r;
	OnigurumaRegex* _tmp5;
	g_return_val_if_fail (pattern != NULL, NULL);
	(*error) = NULL;
	rx = oniguruma_regex_new ();
	c_pattern = ((gchar*) (pattern));
	rx1 = NULL;
	_tmp2 = NULL;
	_tmp0 = NULL;
	r = (_tmp1 = onig_new (&_tmp0, c_pattern, (c_pattern + strlen (pattern)), options, ((gint) (ONIG_ENCODING_ASCII)), ONIG_SYNTAX_DEFAULT, &err_info), rx1 = (_tmp2 = _tmp0, (rx1 == NULL ? NULL : (rx1 = ( (rx1), NULL))), _tmp2), _tmp1);
	if (r < 0) {
		OnigurumaOnigError* _tmp3;
		OnigurumaRegex* _tmp4;
		_tmp3 = NULL;
		(*error) = (_tmp3 = oniguruma_onig_error_new (), ((*error) == NULL ? NULL : ((*error) = (g_object_unref ((*error)), NULL))), _tmp3);
		(*error)->code = r;
		(*error)->error_info = err_info;
		_tmp4 = NULL;
		return (_tmp4 = NULL, (rx == NULL ? NULL : (rx = (g_object_unref (rx), NULL))), (rx1 == NULL ? NULL : (rx1 = ( (rx1), NULL))), _tmp4);
	}
	oniguruma_regex_set_rx (rx, rx1);
	_tmp5 = NULL;
	return (_tmp5 = rx, (rx1 == NULL ? NULL : (rx1 = ( (rx1), NULL))), _tmp5);
}


OnigurumaRegex* oniguruma_regex_new (void) {
	OnigurumaRegex * self;
	self = g_object_newv (ONIGURUMA_TYPE_REGEX, 0, NULL);
	return self;
}


regex_t* oniguruma_regex_get_rx (OnigurumaRegex* self) {
	g_return_val_if_fail (ONIGURUMA_IS_REGEX (self), NULL);
	return self->priv->_rx;
}


void oniguruma_regex_set_rx (OnigurumaRegex* self, regex_t* value) {
	regex_t* _tmp2;
	regex_t* _tmp1;
	g_return_if_fail (ONIGURUMA_IS_REGEX (self));
	_tmp2 = NULL;
	_tmp1 = NULL;
	self->priv->_rx = (_tmp2 = (_tmp1 = value, (_tmp1 == NULL ? NULL :  (_tmp1))), (self->priv->_rx == NULL ? NULL : (self->priv->_rx = ( (self->priv->_rx), NULL))), _tmp2);
}


static void oniguruma_regex_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	OnigurumaRegex * self;
	self = ONIGURUMA_REGEX (object);
	switch (property_id) {
		case ONIGURUMA_REGEX_RX:
		g_value_set_pointer (value, oniguruma_regex_get_rx (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void oniguruma_regex_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	OnigurumaRegex * self;
	self = ONIGURUMA_REGEX (object);
	switch (property_id) {
		case ONIGURUMA_REGEX_RX:
		oniguruma_regex_set_rx (self, g_value_get_pointer (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void oniguruma_regex_class_init (OnigurumaRegexClass * klass) {
	oniguruma_regex_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (OnigurumaRegexPrivate));
	G_OBJECT_CLASS (klass)->get_property = oniguruma_regex_get_property;
	G_OBJECT_CLASS (klass)->set_property = oniguruma_regex_set_property;
	G_OBJECT_CLASS (klass)->dispose = oniguruma_regex_dispose;
	g_object_class_install_property (G_OBJECT_CLASS (klass), ONIGURUMA_REGEX_RX, g_param_spec_pointer ("rx", "rx", "rx", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void oniguruma_regex_instance_init (OnigurumaRegex * self) {
	self->priv = ONIGURUMA_REGEX_GET_PRIVATE (self);
}


static void oniguruma_regex_dispose (GObject * obj) {
	OnigurumaRegex * self;
	self = ONIGURUMA_REGEX (obj);
	(self->priv->_rx == NULL ? NULL : (self->priv->_rx = ( (self->priv->_rx), NULL)));
	G_OBJECT_CLASS (oniguruma_regex_parent_class)->dispose (obj);
}


GType oniguruma_regex_get_type (void) {
	static GType oniguruma_regex_type_id = 0;
	if (G_UNLIKELY (oniguruma_regex_type_id == 0)) {
		static const GTypeInfo g_define_type_info = { sizeof (OnigurumaRegexClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) oniguruma_regex_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (OnigurumaRegex), 0, (GInstanceInitFunc) oniguruma_regex_instance_init };
		oniguruma_regex_type_id = g_type_register_static (G_TYPE_OBJECT, "OnigurumaRegex", &g_define_type_info, 0);
	}
	return oniguruma_regex_type_id;
}



