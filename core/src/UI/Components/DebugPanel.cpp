#include "StdInclude.hpp"
#include "DebugPanel.hpp"

#include "Mod.hpp"

namespace IWXMVM::UI
{
	void DebugPanel::Initialize()
	{}

	void DebugPanel::Render()
	{
		ImGui::Begin("Debug", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Text("Game State: %s", Mod::GetGameInterface()->GetGameStateString().c_str());
		ImGui::Text("Demo Name: %s", Mod::GetGameInterface()->GetDemoInfo().name.c_str());
		ImGui::Text("Demo Tick: %d", Mod::GetGameInterface()->GetDemoInfo().currentTick);
		ImGui::Text("Demo End Tick: %d", Mod::GetGameInterface()->GetDemoInfo().endTick);
		ImGui::End();
	}

	void DebugPanel::Release()
	{}
}