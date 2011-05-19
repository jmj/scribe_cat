/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#include <string.h>
#include <thrift.h>
#include <thrift_application_exception.h>
#include "bucket_store_mapping.h"

gboolean
bucket_store_mapping_if_get_mapping (BucketStoreMappingIf *iface, GHashTable ** _return, const gchar * category, BucketStoreMappingException ** e, GError **error)
{
  return BUCKET_STORE_MAPPING_IF_GET_INTERFACE (iface)->get_mapping (iface, _return, category, e, error);
}

GType
bucket_store_mapping_if_get_type (void)
{
  static GType type = 0;
  if (type == 0)
  {
    static const GTypeInfo type_info =
    {
      sizeof (BucketStoreMappingIfInterface),
      NULL,  /* base_init */
      NULL  /* base_finalize */
    };
    type = g_type_register_static (G_TYPE_INTERFACE,
                                   "BucketStoreMappingIf",
                                   &type_info, 0);
  }
  return type;
}

static void 
bucket_store_mapping_if_interface_init (BucketStoreMappingIfInterface *iface);

G_DEFINE_TYPE_WITH_CODE (BucketStoreMappingClient, bucket_store_mapping_client,
                       G_TYPE_OBJECT, 
                         G_IMPLEMENT_INTERFACE (TYPE_BUCKET_STORE_MAPPING_IF,
                                                bucket_store_mapping_if_interface_init));

enum _BucketStoreMappingClientProperties
{
  PROP_0,
  PROP_BUCKET_STORE_MAPPING_CLIENT_INPUT_PROTOCOL,
  PROP_BUCKET_STORE_MAPPING_CLIENT_OUTPUT_PROTOCOL
};

void
bucket_store_mapping_client_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  BucketStoreMappingClient *client = BUCKET_STORE_MAPPING_CLIENT (object);

  THRIFT_UNUSED_VAR (pspec);

  switch (property_id)
  {
    case PROP_BUCKET_STORE_MAPPING_CLIENT_INPUT_PROTOCOL:
      client->input_protocol = g_value_get_object (value);
      break;
    case PROP_BUCKET_STORE_MAPPING_CLIENT_OUTPUT_PROTOCOL:
      client->output_protocol = g_value_get_object (value);
      break;
  }
}

void
bucket_store_mapping_client_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  BucketStoreMappingClient *client = BUCKET_STORE_MAPPING_CLIENT (object);

  THRIFT_UNUSED_VAR (pspec);

  switch (property_id)
  {
    case PROP_BUCKET_STORE_MAPPING_CLIENT_INPUT_PROTOCOL:
      g_value_set_object (value, client->input_protocol);
      break;
    case PROP_BUCKET_STORE_MAPPING_CLIENT_OUTPUT_PROTOCOL:
      g_value_set_object (value, client->output_protocol);
      break;
  }
}

gboolean bucket_store_mapping_client_send_get_mapping (BucketStoreMappingIf * iface, const gchar * category, GError ** error)
{
  gint32 cseqid = 0;
  ThriftProtocol * protocol = BUCKET_STORE_MAPPING_CLIENT (iface)->output_protocol;

  if (thrift_protocol_write_message_begin (protocol, "getMapping", T_CALL, cseqid, error) < 0)
    return FALSE;

  {
    gint32 ret;
    gint32 xfer = 0;

    
    if ((ret = thrift_protocol_write_struct_begin (protocol, "getMapping_args", error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_protocol_write_field_begin (protocol, "category", T_STRING, 1, error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_protocol_write_string (protocol, category, error)) < 0)
      return 0;
    if ((ret = thrift_protocol_write_field_end (protocol, error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_protocol_write_field_stop (protocol, error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_protocol_write_struct_end (protocol, error)) < 0)
      return 0;
    xfer += ret;

  }

  if (thrift_protocol_write_message_end (protocol, error) < 0)
    return FALSE;
  if (!thrift_transport_flush (protocol->transport, error))
    return FALSE;
  if (!thrift_transport_write_end (protocol->transport, error))
    return FALSE;

  return TRUE;
}

gboolean bucket_store_mapping_client_recv_get_mapping (BucketStoreMappingIf * iface, GHashTable ** _return, BucketStoreMappingException ** e, GError ** error)
{

  gint32 rseqid;
  gchar * fname;
  ThriftMessageType mtype;
  ThriftProtocol * protocol = BUCKET_STORE_MAPPING_CLIENT (iface)->input_protocol;

  if (thrift_protocol_read_message_begin (protocol, &fname, &mtype, &rseqid, error) < 0)
  {
    if (fname) g_free (fname);
    return FALSE;
  }

  if (mtype == T_EXCEPTION) {
    if (fname) g_free (fname);
    ThriftApplicationException *xception = g_object_new (THRIFT_TYPE_APPLICATION_EXCEPTION, NULL);
    thrift_struct_read (THRIFT_STRUCT (xception), protocol, NULL);
    thrift_protocol_read_message_end (protocol, NULL);
    thrift_transport_read_end (protocol->transport, NULL);
    g_set_error (error, THRIFT_APPLICATION_EXCEPTION_ERROR, xception->type, "application error: %s", xception->message);
    g_object_unref (xception);
    return FALSE;
  } else if (mtype != T_REPLY) {
    if (fname) g_free (fname);
    thrift_protocol_skip (protocol, T_STRUCT, NULL);
    thrift_protocol_read_message_end (protocol, NULL);
    thrift_transport_read_end (protocol->transport, NULL);
    g_set_error (error, THRIFT_APPLICATION_EXCEPTION_ERROR, THRIFT_APPLICATION_EXCEPTION_ERROR_INVALID_MESSAGE_TYPE, "invalid message type %d, expected T_REPLY", mtype);
    return FALSE;
  } else if (strncmp (fname, "getMapping", 10) != 0) {
    thrift_protocol_skip (protocol, T_STRUCT, NULL);
    thrift_protocol_read_message_end (protocol, error);
    thrift_transport_read_end (protocol->transport, error);
    g_set_error (error, THRIFT_APPLICATION_EXCEPTION_ERROR, THRIFT_APPLICATION_EXCEPTION_ERROR_WRONG_METHOD_NAME, "wrong method name %s, expected getMapping", fname);
    if (fname) g_free (fname);
    return FALSE;
  }
  if (fname) g_free (fname);

  {
    gint32 ret;
    gint32 xfer = 0;
    gchar *name;
    ThriftType ftype;
    gint16 fid;
    guint32 len = 0;
    gpointer data = NULL;
    

    /* satisfy -Wall in case these aren't used */
    THRIFT_UNUSED_VAR (len);
    THRIFT_UNUSED_VAR (data);

    /* read the struct begin marker */
    if ((ret = thrift_protocol_read_struct_begin (protocol, &name, error)) < 0)
    {
      if (name) g_free (name);
      return 0;
    }
    xfer += ret;
    if (name) g_free (name);

    /* read the struct fields */
    while (1)
    {
      /* read the beginning of a field */
      if ((ret = thrift_protocol_read_field_begin (protocol, &name, &ftype, &fid, error)) < 0)
      {
        if (name) g_free (name);
        return 0;
      }
      xfer += ret;
      if (name) g_free (name);

      /* break if we get a STOP field */
      if (ftype == T_STOP)
      {
        break;
      }

      switch (fid)
      {
        case 0:
          if (ftype == T_MAP)
          {
            {
              guint32 size;
              ThriftType key_type;
              ThriftType value_type;

              /* read the map begin marker */
              if ((ret = thrift_protocol_read_map_begin (protocol, &key_type, &value_type, &size, error)) < 0)
                return 0;
              xfer += ret;

              /* iterate through each of the map's fields */
              guint32 i;
              for (i = 0; i < size; i++)
              {
                gint32* key0 = g_new (gint32, 1);
                HostPort * val1;
                if ((ret = thrift_protocol_read_i32 (protocol, &*key0, error)) < 0)
                  return 0;
                xfer += ret;
                val1 = g_object_new (TYPE_HOST_PORT, NULL);
                if ((ret = thrift_struct_read (THRIFT_STRUCT (val1), protocol, error)) < 0)
                  return 0;
                xfer += ret;
                g_hash_table_insert ((GHashTable *)*_return, (gpointer) key0, (gpointer) &val1);
              }

              /* read the map end marker */
              if ((ret = thrift_protocol_read_map_end (protocol, error)) < 0)
                return 0;
              xfer += ret;
            }
          } else {
            if ((ret = thrift_protocol_skip (protocol, ftype, error)) < 0)
              return 0;
            xfer += ret;
          }
          break;
        case 1:
          if (ftype == T_STRUCT)
          {
            *e = g_object_new (TYPE_BUCKET_STORE_MAPPING_EXCEPTION, NULL);
            if ((ret = thrift_struct_read (THRIFT_STRUCT (*e), protocol, error)) < 0)
              return 0;
            xfer += ret;
          } else {
            if ((ret = thrift_protocol_skip (protocol, ftype, error)) < 0)
              return 0;
            xfer += ret;
          }
          break;
        default:
          if ((ret = thrift_protocol_skip (protocol, ftype, error)) < 0)
            return 0;
          xfer += ret;
          break;
      }
      if ((ret = thrift_protocol_read_field_end (protocol, error)) < 0)
        return 0;
      xfer += ret;
    }

    if ((ret = thrift_protocol_read_struct_end (protocol, error)) < 0)
      return 0;
    xfer += ret;

  }

  if (thrift_protocol_read_message_end (protocol, error) < 0)
    return FALSE;

  if (!thrift_transport_read_end (protocol->transport, error))
    return FALSE;

  if (*e != NULL)
  {
      g_set_error (error, BUCKET_STORE_MAPPING_EXCEPTION_ERROR, BUCKET_STORE_MAPPING_EXCEPTION_ERROR_CODE, "BucketStoreMappingException");
      return FALSE;
  }
  return TRUE;
}

gboolean bucket_store_mapping_client_get_mapping (BucketStoreMappingIf * iface, GHashTable ** _return, const gchar * category, BucketStoreMappingException ** e, GError ** error)
{
  if (!bucket_store_mapping_client_send_get_mapping (iface, category, error))
    return FALSE;
  if (!bucket_store_mapping_client_recv_get_mapping (iface, _return, e, error))
    return FALSE;
  return TRUE;
}

static void
bucket_store_mapping_if_interface_init (BucketStoreMappingIfInterface *iface)
{
  iface->get_mapping = bucket_store_mapping_client_get_mapping;
}

static void
bucket_store_mapping_client_init (BucketStoreMappingClient *client)
{
  client->input_protocol = NULL;
  client->output_protocol = NULL;
}

static void
bucket_store_mapping_client_class_init (BucketStoreMappingClientClass *cls)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (cls);
  GParamSpec *param_spec;

  gobject_class->set_property = bucket_store_mapping_client_set_property;
  gobject_class->get_property = bucket_store_mapping_client_get_property;

  param_spec = g_param_spec_object ("input_protocol",
                                    "input protocol (construct)",
                                    "Set the client input protocol",
                                    THRIFT_TYPE_PROTOCOL,
                                    G_PARAM_READWRITE);
  g_object_class_install_property (gobject_class,
                                   PROP_BUCKET_STORE_MAPPING_CLIENT_INPUT_PROTOCOL, param_spec);

  param_spec = g_param_spec_object ("output_protocol",
                                    "output protocol (construct)",
                                    "Set the client output protocol",
                                    THRIFT_TYPE_PROTOCOL,
                                    G_PARAM_READWRITE);
  g_object_class_install_property (gobject_class,
                                   PROP_BUCKET_STORE_MAPPING_CLIENT_OUTPUT_PROTOCOL, param_spec);
}
