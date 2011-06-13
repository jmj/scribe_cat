#include <transport/thrift_transport.h>
#include <transport/thrift_socket.h>
#include <transport/thrift_server_transport.h>
#include <transport/thrift_server_socket.h>
#include <transport/thrift_framed_transport.h>
#include <protocol/thrift_protocol.h>
#include <protocol/thrift_binary_protocol.h>

#include "gen-c_glib/scribe.h"
#include "gen-c_glib/scribe_types.h"

#ifndef NOMAIN
int main(int argc, char **argv) {
#else
int log(){
#endif /* NOMAIN */

    g_type_init();

    ThriftTransport *transport = NULL;
    ThriftSocket *tsocket = NULL;
    ThriftBinaryProtocol *protocol = NULL;
    scribeClient *client = NULL;
    scribeIf *iface = NULL;

    ResultCode result;
    LogEntry *log = NULL;
    GPtrArray * messages = NULL;

    GError *error = NULL;

    tsocket = g_object_new(THRIFT_TYPE_SOCKET, "hostname", "localhost",
        "port", 1463, NULL);
    transport = g_object_new(THRIFT_TYPE_FRAMED_TRANSPORT, "transport",
        THRIFT_TRANSPORT(tsocket), NULL);
    protocol = g_object_new(THRIFT_TYPE_BINARY_PROTOCOL, "transport",
        THRIFT_TRANSPORT(transport), NULL);
    client = g_object_new(TYPE_SCRIBE_CLIENT,
        "input_protocol", THRIFT_PROTOCOL(protocol),
        "output_protocol", THRIFT_PROTOCOL(protocol), NULL);
    iface = SCRIBE_IF(client);

    thrift_transport_open(THRIFT_TRANSPORT(tsocket), NULL);

    messages = g_ptr_array_new();

    log = g_object_new(TYPE_LOG_ENTRY, NULL);
    log->category = "TEST";
    log->message = "This is a test message\n\0";

    g_ptr_array_add(messages, log);
    scribe_client_log(iface, &result, messages, &error);
    return 0;

}
