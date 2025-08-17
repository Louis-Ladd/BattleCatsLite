#ifndef SCENE_H_
#define SCENE_H_

#include "../cats/cat.h"
#include "../entity/entity.h"
#include "../entity/entity_behavior.h"
#include "../input/keyboard.h"
#include "../render/sprite.h"
#include "../ui/uimanager.h"
#include "SDL2/SDL.h"

#define SCENE_ASSET_COUNT 2

enum AssetType
{
	BACKDROP,
	SPRITESHEET
};

typedef struct
{
	enum AssetType type;
	void* asset;
} SceneAsset;

typedef struct
{
	u16 entity_count;
	Entity** entities;
	SceneAsset scene_assets[SCENE_ASSET_COUNT];
	GenericUIElementList scene_ui;
} Scene;

Scene* CreateScene();

void RenderScene(Scene* scene);

void RenderAssets(SceneAsset assets[SCENE_ASSET_COUNT]);

void AddEntity(Scene* scene, Entity* entity);

void RemoveEntity(Scene* scene, Entity* entity);

void UpdateScene(Scene* scene);

void DestroyScene(Scene* scene);

#endif
