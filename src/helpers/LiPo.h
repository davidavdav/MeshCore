#pragma once

// 1S LiPo: map terminal voltage (V) to estimated state-of-charge 0..100% using
// piecewise-linear segments from a common voltage chart (see LiPo.cpp).
float lipo_volts_to_percent(float voltage_volts);
