#pragma once

#include <wxModularCore.h>
#include <wxNonGuiPluginBase.h>
#include <wxGuiPluginBase.h>

// We need to know which DLL produced the specific plugin object.
WX_DECLARE_HASH_MAP(wxNonGuiPluginBase*, wxDynamicLibrary*, \
					wxPointerHash, wxPointerEqual, \
					wxNonGuiPluginToDllDictionary);
WX_DECLARE_HASH_MAP(wxGuiPluginBase*, wxDynamicLibrary*, \
					wxPointerHash, wxPointerEqual, \
					wxGuiPluginToDllDictionary);
// And separate list of loaded plugins for faster access.
WX_DECLARE_LIST(wxNonGuiPluginBase, wxNonGuiPluginBaseList);
WX_DECLARE_LIST(wxGuiPluginBase, wxGuiPluginBaseList);

class SampleModularCore : public wxModularCore
{
public:
	virtual ~SampleModularCore();

	/// load the plugins, and set all the plugins' event handler to the same common one
	virtual bool LoadAllPlugins(bool forceProgramPath) override;
	virtual bool UnloadAllPlugins() override;

	const wxNonGuiPluginBaseList & GetNonGuiPlugins() const;
	const wxGuiPluginBaseList & GetGuiPlugins() const;
private:
	wxNonGuiPluginToDllDictionary m_MapNonGuiPluginsDll;
	wxNonGuiPluginBaseList m_NonGuiPlugins;
	wxGuiPluginToDllDictionary m_MapGuiPluginsDll;
	wxGuiPluginBaseList m_GuiPlugins;
};
