#include "Game.h"
#include "Includes.h"
void Game::LoadResources()
{
	//---------------------------------------------------------------------------------------------------------
	// Load up the managers
	//---------------------------------------------------------------------------------------------------------
	// Create/Load Shader 
	ShaderMan::addShader(ShaderName::SPRITE, "spriteRender");
	ShaderMan::addShader(ShaderName::SPRITE_LINE, "spriteLineRender");

	// Textures
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/unsorted.tga", TextName::Characters);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/woodBlocks.tga", TextName::WoodBlocks);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/glassBlocks.tga", TextName::GlassBlocks);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/stoneBlocks.tga", TextName::StoneBlocks);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/slingV2.tga", TextName::Sling);

	// Images
	ImageMan::addImage(ImageName::KingPig, TextName::Characters, Rect(40, 1, 127, 153));
	ImageMan::addImage(ImageName::QueenPig, TextName::Characters, Rect(40, 466, 127, 153));

	ImageMan::addImage(ImageName::RedBird, TextName::Characters, Rect(903, 798, 46, 45));
	ImageMan::addImage(ImageName::BlueBird, TextName::Characters, Rect(0, 378, 32, 31));
	ImageMan::addImage(ImageName::YellowBird, TextName::Characters, Rect(667, 879, 59, 55));
	ImageMan::addImage(ImageName::GreenBird, TextName::Characters, Rect(932, 529, 99, 72));
	ImageMan::addImage(ImageName::WhiteBird, TextName::Characters, Rect(409, 352, 81, 94));
	ImageMan::addImage(ImageName::BlackBird, TextName::Characters, Rect(409, 725, 62, 80));
	ImageMan::addImage(ImageName::BigRedBird, TextName::Characters, Rect(298, 752, 97, 95));

	ImageMan::addImage(ImageName::WoodBlockShort, TextName::WoodBlocks, Rect(288, 344, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed, TextName::WoodBlocks, Rect(288, 257, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong, TextName::WoodBlocks, Rect(288, 169, 205, 21));

	ImageMan::addImage(ImageName::WoodBlockShort2, TextName::WoodBlocks, Rect(288, 368, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed2, TextName::WoodBlocks, Rect(288, 281, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong2, TextName::WoodBlocks, Rect(288, 191, 205, 21));

	ImageMan::addImage(ImageName::WoodBlockShort3, TextName::WoodBlocks, Rect(371, 344, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed3, TextName::WoodBlocks, Rect(288, 302, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong3, TextName::WoodBlocks, Rect(288, 212, 205, 21));

	ImageMan::addImage(ImageName::WoodBlockShort4, TextName::WoodBlocks, Rect(371, 368, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed4, TextName::WoodBlocks, Rect(288, 323, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong4, TextName::WoodBlocks, Rect(288, 235, 205, 21));

	ImageMan::addImage(ImageName::GlassBlockShort, TextName::GlassBlocks, Rect(288, 346, 83, 21));
	ImageMan::addImage(ImageName::GlassBlockMed, TextName::GlassBlocks, Rect(288, 259, 168, 21));
	ImageMan::addImage(ImageName::GlassBlockLong, TextName::GlassBlocks, Rect(288, 215, 205, 21));

	ImageMan::addImage(ImageName::Bang, TextName::Characters, Rect(674, 354, 87, 89));

	ImageMan::addImage(ImageName::SlingShotRight, TextName::Characters, Rect(0, 0, 38, 200));
	ImageMan::addImage(ImageName::SlingShotLeft, TextName::Characters, Rect(832, 0, 45, 125));
	ImageMan::addImage(ImageName::Sling, TextName::Sling, Rect(0, 0, 18, 23));
}