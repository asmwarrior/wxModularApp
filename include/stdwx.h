#ifndef IFLOOR_STDWX_H_
#define IFLOOR_STDWX_H_

// SYSTEM INCLUDES
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif


/* definition to expand macro then apply to pragma message */
#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)


// copy code from: https://github.com/wxWidgets/wxWidgets/blob/master/include/wx/dlimpexp.h
// the wx 3.0's the wx/dlimpexp.h is already included, but it does not have the
// gcc version check (!wxCHECK_GCC_VERSION(4, 5) || wxCHECK_GCC_VERSION(4, 7)) as below
// it only checks gcc 4.5 above
// In file included from F:\msys2\mingw64\include\wx-3.0/wx/defs.h:570,
//                  from F:\msys2\mingw64\include\wx-3.0/wx/wxprec.h:12,
//                  from ..\include/stdwx.h:6,
// but the WXEXPORT is defined as empty in that file, we have to redefine it, so

#if defined(WXEXPORT)
    #undef WXEXPORT
#endif

#if defined(WXIMPORT)
    #undef WXIMPORT
#endif


#if defined(HAVE_VISIBILITY)
#    define WXEXPORT __attribute__ ((visibility("default")))
#    define WXIMPORT __attribute__ ((visibility("default")))
#elif defined(__WINDOWS__)
    /*
       __declspec works in as VC++.
     */
#    if defined(__VISUALC__)
#        define WXEXPORT __declspec(dllexport)
#        define WXIMPORT __declspec(dllimport)
    /*
        While gcc also supports __declspec(dllexport), it created unusably huge
        DLL files in gcc 4.[56] (while taking horribly long amounts of time),
        see http://gcc.gnu.org/bugzilla/show_bug.cgi?id=43601. Because of this
        we rely on binutils auto export/import support which seems to work
        quite well for 4.5+. However the problem was fixed in 4.7 and later and
        not exporting everything creates smaller DLLs (~8% size difference), so
        do use the explicit attributes again for the newer versions.
     */
#    elif defined(__GNUC__) && \
        (!wxCHECK_GCC_VERSION(4, 5) || wxCHECK_GCC_VERSION(4, 7))
        /*
            __declspec could be used here too but let's use the native
            __attribute__ instead for clarity.
        */
#       define WXEXPORT __attribute__((dllexport))
#       define WXIMPORT __attribute__((dllimport))
#    endif
#elif defined(__CYGWIN__)
#    define WXEXPORT __declspec(dllexport)
#    define WXIMPORT __declspec(dllimport)
#endif

/* for other platforms/compilers we don't anything */
#ifndef WXEXPORT
#    define WXEXPORT
#    define WXIMPORT
#endif

//#pragma message(VAR_NAME_VALUE(WXEXPORT))

#if defined(__WXMSW__)
#include <wx/msw/wrapwin.h> // includes <windows.h> safely
#include <winnt.h>
#define PLUGIN_EXPORTED_API	extern "C" WXEXPORT
#else
#define PLUGIN_EXPORTED_API	extern "C"
#endif

#include <wx/cmdline.h>
#include <wx/config.h>
#include <wx/defs.h>
#include <wx/dir.h>
#include <wx/display.h>
#include <wx/dynlib.h>
#include <wx/dynload.h>
#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/frame.h>
#include <wx/glcanvas.h>
#include <wx/hashmap.h>
#include <wx/image.h>
#include <wx/imaglist.h>
#include <wx/intl.h>
#include <wx/list.h>
#include <wx/notebook.h>
#include <wx/stdpaths.h>
#include <wx/sstream.h>
#include <wx/thread.h>
#include <wx/treebook.h>
#include <wx/wfstream.h>
#include <wx/wupdlock.h>
#include <wx/textfile.h>
#include <wx/socket.h>
#include <wx/mimetype.h>
#include <wx/ipc.h>

// APPLICATION INCLUDES
#endif
