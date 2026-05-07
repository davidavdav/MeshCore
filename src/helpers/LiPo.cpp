#include "LiPo.h"

// Voltage breakpoints (V) for 1S LiPo, high to low; 20 intervals of 5% each.
// Source table: https://intofpv.com/t-lipo-voltage-quick-chart
float lipo_volts_to_percent(float voltage_volts) {
  static const float volt_table[21] = {
      4.20f, 4.15f, 4.11f, 4.08f, 4.02f, 3.98f, 3.95f, 3.91f, 3.87f, 3.85f,
      3.84f, 3.82f, 3.80f, 3.79f, 3.77f, 3.75f, 3.73f, 3.71f, 3.69f, 3.61f, 3.27f,
  };

  const float step = 5.0f;
  const float v = voltage_volts;

  if (v >= volt_table[0]) {
    return 100.0f;
  }
  if (v <= volt_table[20]) {
    return 0.0f;
  }

  for (int i = 0; i < 20; i++) {
    if (v >= volt_table[i + 1]) {
      const float v_high = volt_table[i];
      const float v_low = volt_table[i + 1];
      const float p_high = 100.0f - (static_cast<float>(i) * step);
      const float p_low = 100.0f - (static_cast<float>(i + 1) * step);
      return p_low + (v - v_low) * (p_high - p_low) / (v_high - v_low);
    }
  }

  return 0.0f;
}
