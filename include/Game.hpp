#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <chrono>
#include <random>
#include "imgui.h"
#include "TextureManager.hpp"

struct Color
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};

struct Particle
{
	SDL_FRect rect{};
	Color color;
	bool isShowing{false};
	SDL_Texture *texture;
	void ShiftParticleDown(int index);
	void ShiftParticleLeftOrRight(int index);
};


class Game
{

public:
	Game();

	~Game();

	bool InitGame();
	void SimulationLoop();
	void EndSimulation();

	SDL_Renderer *GetRenderer()
	{
		return mRenderer;
	}
	SDL_Window *GetWindow()
	{
		return mWindow;
	}
	int GetColumns() const
	{
		return mColumns;
	}
	int GetRows() const
	{
		return mRows;
	}

	int GetSandSize() const
	{
		return mSandSize;
	}

private:
	void HandleInput();
	void UpdateParticles();
	void Render();
	void RebuildGrid();
	void ShiftParticleDown(int index);
	void ShiftParticleLeftOrRight(int index);

private:
	Uint64 mCurrentFrameTime;
	Uint64 mPreviousFrameTime;

	int mScreenWidth;
	int mScreenHeight;
	int mRows;
	int mColumns;
	int mMouseAreaSize;
	int mAmountShowingOnGrid;
	int mRandomNum;
	int mSandSize;

	bool mMouseDown;
	bool mDone = false;

	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	SDL_FRect mMouseArea;
	SDL_Texture *mTexture;
	
	std::vector<Particle> mGrid;
	std::vector<Particle> mParticles;
	std::mt19937 mRng;
	std::uniform_int_distribution<> mDistrib;

	TextureManager textureManager;

	ImGuiIO mIO;
};
