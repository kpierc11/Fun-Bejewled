#include "TextureManager.hpp"

TextureManager::TextureManager()
{
}

TextureManager::TextureManager(SDL_Surface *surface, char *bmpPath, std::string filePath) : mSurface(surface), mBmpPath(bmpPath), mFilePath(filePath)
{
}

TextureManager::~TextureManager()
{
}

SDL_Texture *TextureManager::LoadTexture(SDL_Renderer *renderer)
{

    SDL_asprintf(&mBmpPath, "%smFilePath", SDL_GetBasePath());

    SDL_Surface *surface = SDL_LoadBMP(mBmpPath);
    if (!surface)
    {
        // SDL_Log("Couldn't load bitmap: %s", SDL_GetError());
        return nullptr;
    }

    SDL_free(mBmpPath);

    mTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!mTexture)
    {
        //SDL_Log("Couldn't create static texture: %s", SDL_GetError());
        return nullptr;
    }

    SDL_DestroySurface(surface);

    return mTexture;
}
