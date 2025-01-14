#pragma once
#include "StdInclude.hpp"

namespace IWXMVM
{
	struct Dvar
	{
		std::string name;
		union Value
		{
			float floating_point;
			uint32_t uint32;
			int32_t int32;
			float vector[4];
			const char* string;
			uint8_t color[4];
		}* value;
	};

	class GameInterface
	{
	public:

		enum class Game
		{
			None, IW3
		};

		enum class GameState
		{
			MainMenu,
			InGame,
			InDemo
		};

		enum class MouseMode
		{
			Capture, Passthrough
		};

		GameInterface(const Game game) : game(game) {}
		virtual ~GameInterface() = default;

		Game GetGame() const { return game; }

		std::string GetGameName() const
		{
			switch (game)
			{
			case Game::IW3:
				return "IW3";
			case Game::None:
			default:
				return "Unknown Game";
			}
		}

		virtual void InstallHooks() = 0;
		virtual void SetupEventListeners() = 0;

		virtual IDirect3DDevice9* GetD3D9Device() = 0;
		virtual HWND GetWindowHandle() = 0;
		virtual uintptr_t GetWndProc() = 0;
		virtual void SetMouseMode(MouseMode mode) = 0;
		virtual GameState GetGameState() = 0;

		std::string GetGameStateString()
		{
			switch (GetGameState())
			{
			case GameState::MainMenu:
				return "Main Menu";
			case GameState::InDemo:
				return "Playing Demo";
			case GameState::InGame:
				return "In Game";
			default:
				return "Unknown Game";
			}
		}


		struct DemoInfo
		{
			std::string name;
			std::string path;

			uint32_t currentTick;
			uint32_t endTick;
		};

		virtual DemoInfo GetDemoInfo() = 0;


		virtual void ToggleDemoPlaybackState() = 0;
		virtual bool IsDemoPlaybackPaused() = 0;

		virtual std::optional<Dvar> GetDvar(const std::string name) = 0;

	private:
		Game game;
	};
}