#include <AP_HAL/AP_HAL.h>
#include <GCS_MAVLink/GCS.h>     // because of CHECK_PAYLOAD_SIZE

#include "DroneShowLED_Debug.h"

DroneShowLED_Debug::DroneShowLED_Debug() : DroneShowLED(),
    _last_red(0),
    _last_green(0),
    _last_blue(0)
{
}

bool DroneShowLED_Debug::set_raw_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
    static uint32_t last_sent_at = 0;
    uint32_t now = AP_HAL::millis();

    if (now - last_sent_at >= 100) {
        gcs().send_text(MAV_SEVERITY_INFO, "%02X%02X%02X", red, green, blue);
        return true;
    } else {
        return false;
    }
}
