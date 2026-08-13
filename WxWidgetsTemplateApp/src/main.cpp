#include "WxWidgetsTemplateApp.hpp"

#if defined( TEMPLATE_APP_WINDOWS_SUBSYSTEM )
wxIMPLEMENT_APP( TemplateApp );
#else
wxIMPLEMENT_APP_CONSOLE( TemplateApp );
#endif  // TEMPLATE_APP_WINDOWS_SUBSYSTEM
