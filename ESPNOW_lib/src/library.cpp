#include <stdint.h>

#include "ESPNOW_manager.h"
#include "ESPNOW_types.h"
#include "stdio.h"

extern "C" {
    ESPNOW_manager *espnow_start(const char *interface, uint8_t dest_mac[6]) {
        auto handler = new ESPNOW_manager(interface);
        handler->set_dst_mac(dest_mac);
        handler->set_datarate(DATARATE_12Mbps);
        handler->set_channel(1);
        handler->start();
        return handler;
    }

    int espnow_send(ESPNOW_manager *espnow, uint8_t *payload, int len) {
        return espnow->send(payload, len);
    }

    void espnow_end(ESPNOW_manager *espnow) {
        espnow->end();
        delete espnow;
    }
}