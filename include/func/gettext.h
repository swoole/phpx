#pragma once

#include "phpx.h"
#include "phpx_literal_string.h"
#include "phpx_class.h"

namespace php {

Variant textdomain(const Variant &domain = nullptr);
Variant gettext(const Variant &message);
Variant _(const Variant &message);
Variant dgettext(const Variant &domain, const Variant &message);
Variant dcgettext(const Variant &domain, const Variant &message, const Variant &category);
Variant bindtextdomain(const Variant &domain, const Variant &directory = nullptr);
Variant ngettext(const Variant &singular, const Variant &plural, const Variant &count);
Variant dngettext(const Variant &domain, const Variant &singular, const Variant &plural, const Variant &count);
Variant dcngettext(const Variant &domain,
                   const Variant &singular,
                   const Variant &plural,
                   const Variant &count,
                   const Variant &category);
Variant bind_textdomain_codeset(const Variant &domain, const Variant &codeset = nullptr);

}  // namespace php
