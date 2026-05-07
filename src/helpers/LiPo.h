#pragma once

#include <stdint.h>

namespace mesh {
class MainBoard;
}

// Four ADC readings, 10 ms apart; integer average (matches divider settling on typical boards).
uint16_t average_battery_millivolts(mesh::MainBoard& board);

// 1S LiPo: map terminal voltage (V) to estimated state-of-charge 0..100% using
// piecewise-linear segments from a common voltage chart (see LiPo.cpp).
float lipo_volts_to_percent(float voltage_volts);
