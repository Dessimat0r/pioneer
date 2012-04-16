#ifndef _SYSTEMINFOVIEW_H
#define _SYSTEMINFOVIEW_H

#include "libs.h"
#include "gui/Gui.h"
#include "View.h"
#include "View.h"
#include <vector>

#define COMM_SELF "#fffCommodity trade analysis of #ff0%s#fff:"
#define COMM_COMP "#fffCommodity trade analysis of #ff0%s#fff against #ff0%s#fff (current system):"

class StarSystem;
class SBody;
namespace Graphics { class Renderer; }

class SystemInfoView: public View {
public:
	SystemInfoView();
	virtual void Update();
	virtual void Draw3D();
	virtual void OnSwitchTo();
	void NextPage();
private:
	class BodyIcon : public Gui::ImageRadioButton {
	public:
		BodyIcon(const char* img);
		virtual void Draw();
		virtual void OnActivate();
		void SetRenderer(Graphics::Renderer *r) { m_renderer = r; }
	private:
		Graphics::Renderer *m_renderer;
	};
	void SystemChanged(const SystemPath &path);
	void UpdateEconomyTab();
	void OnBodyViewed(SBody *b);
	void OnBodySelected(SBody *b);
	void OnClickBackground(Gui::MouseButtonEvent *e);
	void PutBodies(SBody *body, Gui::Fixed *container, int dir, float pos[2], int &majorBodies, int &starports, float &prevSize);
	void UpdateIconSelections();
	Gui::VBox *m_infoBox;
	Gui::Fixed *m_econInfo;
	Gui::Fixed *m_econMajImport, *m_econMinImport;
	Gui::Fixed *m_econMajExport, *m_econMinExport;
	Gui::Fixed *m_econIllegal;
	Gui::Fixed *m_sbodyInfoTab, *m_econInfoTab;
	
	Gui::Label *m_commodityTradeLabel;
	Gui::Tabbed *m_tabs;
	RefCountedPtr<StarSystem> m_system;
	bool m_refresh;
	//map is not enough to associate icons as each tab has their own
	std::vector<std::pair<std::string, BodyIcon*> > m_bodyIcons;
};

#endif /* _SYSTEMINFOVIEW_H */
