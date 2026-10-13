#pragma once

namespace php::detail {

// Process-lifetime state initialized centrally by php::request_init().
void initializeEmptyString() noexcept;
void initializeClosureCarrierHandlers() noexcept;

} // namespace php::detail

namespace php::python {

void initializeNativeApi() noexcept;

} // namespace php::python
