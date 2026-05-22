#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant cal_days_in_month(const Variant &calendar, const Variant &month, const Variant &year);
Variant cal_from_jd(const Variant &julian_day, const Variant &calendar);
Variant cal_info(const Variant &calendar = -1);
Variant cal_to_jd(const Variant &calendar, const Variant &month, const Variant &day, const Variant &year);
Variant easter_date(const Variant &year = nullptr, const Variant &mode = 0);
Variant easter_days(const Variant &year = nullptr, const Variant &mode = 0);
Variant frenchtojd(const Variant &month, const Variant &day, const Variant &year);
Variant gregoriantojd(const Variant &month, const Variant &day, const Variant &year);
Variant jddayofweek(const Variant &julian_day, const Variant &mode = 0);
Variant jdmonthname(const Variant &julian_day, const Variant &mode);
Variant jdtofrench(const Variant &julian_day);
Variant jdtogregorian(const Variant &julian_day);
Variant jdtojewish(const Variant &julian_day, const Variant &hebrew = false, const Variant &flags = 0);
Variant jdtojulian(const Variant &julian_day);
Variant jdtounix(const Variant &julian_day);
Variant jewishtojd(const Variant &month, const Variant &day, const Variant &year);
Variant juliantojd(const Variant &month, const Variant &day, const Variant &year);
Variant unixtojd(const Variant &timestamp = nullptr);

}  // namespace php
