#pragma once

/* Embedders may replace the checked polymorphic cast policy. Builds without
 * RTTI rely on the Zend resource-id check before making the static cast. */
#ifndef PHPX_POLYMORPHIC_CAST
#ifdef PHPX_NO_RTTI
#define PHPX_POLYMORPHIC_CAST(type, value) static_cast<type>(value)
#else
#define PHPX_POLYMORPHIC_CAST(type, value) dynamic_cast<type>(value)
#endif
#endif
