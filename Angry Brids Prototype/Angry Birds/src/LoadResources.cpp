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
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/woodPlatform.tga", TextName::Platform);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/woodBlocks.tga", TextName::WoodBlocks);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/glassBlocks.tga", TextName::GlassBlocks);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/stoneBlocks.tga", TextName::StoneBlocks);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/slingV2.tga", TextName::Sling);
	TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/AngryBirdBackground.tga", TextName::Background);

	// Images
	ImageMan::addImage(ImageName::Background, TextName::Background, Rect(0, 0, 1280, 1336));

	ImageMan::addImage(ImageName::Blast1, TextName::Characters, Rect(1005, 0, 40, 40));
	ImageMan::addImage(ImageName::Blast2, TextName::Characters, Rect(870, 604, 80, 80));
	ImageMan::addImage(ImageName::Blast3, TextName::Characters, Rect(912, 257, 98, 93));
	ImageMan::addImage(ImageName::Blast4, TextName::Characters, Rect(168, 400, 116, 112));
	ImageMan::addImage(ImageName::Blast5, TextName::Characters, Rect(698, 0, 133, 130));
	ImageMan::addImage(ImageName::Blast6, TextName::Characters, Rect(552, 0, 145, 138));

	ImageMan::addImage(ImageName::Platform, TextName::Platform, Rect(0, 0, 165, 44));

	ImageMan::addImage(ImageName::KingPig, TextName::Characters, Rect(40, 1, 127, 153));
	ImageMan::addImage(ImageName::QueenPig, TextName::Characters, Rect(40, 466, 127, 153));


	ImageMan::addImage(ImageName::RegularPig, TextName::Characters, Rect(587, 607, 80, 78));
	ImageMan::addImage(ImageName::RegularPig2, TextName::Characters, Rect(748, 528, 80, 78));
	ImageMan::addImage(ImageName::RegularPig3, TextName::Characters, Rect(587, 838, 80, 78));
	ImageMan::addImage(ImageName::HelmetPig, TextName::Characters, Rect(493, 615, 93, 83));
	ImageMan::addImage(ImageName::HelmetPig2, TextName::Characters, Rect(493, 700, 93, 83));
	ImageMan::addImage(ImageName::HelmetPig3, TextName::Characters, Rect(493, 870, 93, 83));

	ImageMan::addImage(ImageName::RedBird, TextName::Characters, Rect(903, 798, 46, 45));
	ImageMan::addImage(ImageName::BlueBird, TextName::Characters, Rect(0, 378, 32, 31));
	ImageMan::addImage(ImageName::YellowBird, TextName::Characters, Rect(667, 879, 59, 55));
	ImageMan::addImage(ImageName::GreenBird, TextName::Characters, Rect(932, 529, 99, 72));
	ImageMan::addImage(ImageName::WhiteBird, TextName::Characters, Rect(409, 352, 81, 94));
	ImageMan::addImage(ImageName::BlackBird, TextName::Characters, Rect(409, 725, 62, 80));
	ImageMan::addImage(ImageName::BigRedBird, TextName::Characters, Rect(298, 752, 97, 95));

	ImageMan::addImage(ImageName::RedBirdDamaged, TextName::Characters, Rect(852, 890, 46, 45));
	ImageMan::addImage(ImageName::BlueBirdDamaged, TextName::Characters, Rect(0, 409, 32, 31));
	ImageMan::addImage(ImageName::YellowBirdDamaged, TextName::Characters, Rect(792, 743, 59, 55));
	ImageMan::addImage(ImageName::GreenBirdDamaged, TextName::Characters, Rect(950, 604, 99, 72));
	ImageMan::addImage(ImageName::WhiteBirdDamaged, TextName::Characters, Rect(409, 636, 81, 90));
	ImageMan::addImage(ImageName::BlackBirdDamaged, TextName::Characters, Rect(667, 676, 62, 80));
	ImageMan::addImage(ImageName::BigRedBirdDamaged, TextName::Characters, Rect(812, 257, 97, 95));

	ImageMan::addImage(ImageName::RedBirdFlying, TextName::Characters, Rect(950, 798, 46, 45));
	ImageMan::addImage(ImageName::BlueBirdFlying, TextName::Characters, Rect(0, 537, 32, 31));
	ImageMan::addImage(ImageName::YellowBirdFlying, TextName::Characters, Rect(731, 800, 60, 55));
	ImageMan::addImage(ImageName::GreenBirdFlying, TextName::Characters, Rect(830, 529, 99, 72));
	ImageMan::addImage(ImageName::WhiteBirdFlying, TextName::Characters, Rect(409, 542, 81, 94));
	ImageMan::addImage(ImageName::BlackBirdFlying, TextName::Characters, Rect(777, 445, 62, 80));
	ImageMan::addImage(ImageName::BigRedBirdFlying, TextName::Characters, Rect(634, 156, 97, 95));

	ImageMan::addImage(ImageName::RedBirdBlink, TextName::Characters, Rect(956, 845, 50, 42));
	ImageMan::addImage(ImageName::BlueBirdBlink, TextName::Characters, Rect(0, 507, 32, 31));
	ImageMan::addImage(ImageName::YellowBirdBlink, TextName::Characters, Rect(731, 743, 59, 55));
	ImageMan::addImage(ImageName::GreenBirdBlink, TextName::Characters, Rect(668, 604, 99, 72));
	ImageMan::addImage(ImageName::WhiteBirdBlink, TextName::Characters, Rect(409, 447, 81, 94));
	ImageMan::addImage(ImageName::BlackBirdBlink, TextName::Characters, Rect(714, 445, 62, 80));
	ImageMan::addImage(ImageName::BigRedBirdBlink, TextName::Characters, Rect(812, 257, 97, 95));

	ImageMan::addImage(ImageName::WhiteBirdShrivelled, TextName::Characters, Rect(668, 751, 39, 66));
	ImageMan::addImage(ImageName::YellowBirdSuper, TextName::Characters, Rect(861, 743, 72, 55));

	ImageMan::addImage(ImageName::WoodBlockShort, TextName::WoodBlocks, Rect(288, 344, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed, TextName::WoodBlocks, Rect(288, 257, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong, TextName::WoodBlocks, Rect(288, 169, 205, 21));

	ImageMan::addImage(ImageName::WoodBlockShort2, TextName::WoodBlocks, Rect(288, 366, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed2, TextName::WoodBlocks, Rect(288, 278, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong2, TextName::WoodBlocks, Rect(288, 191, 205, 21));

	ImageMan::addImage(ImageName::WoodBlockShort3, TextName::WoodBlocks, Rect(372, 344, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed3, TextName::WoodBlocks, Rect(288, 300, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong3, TextName::WoodBlocks, Rect(288, 212, 205, 21));

	ImageMan::addImage(ImageName::WoodBlockShort4, TextName::WoodBlocks, Rect(372, 366, 83, 21));
	ImageMan::addImage(ImageName::WoodBlockMed4, TextName::WoodBlocks, Rect(288, 323, 168, 21));
	ImageMan::addImage(ImageName::WoodBlockLong4, TextName::WoodBlocks, Rect(288, 235, 205, 21));

	ImageMan::addImage(ImageName::WoodBlockTiny, TextName::WoodBlocks, Rect(457, 255, 41, 21));
	ImageMan::addImage(ImageName::WoodBlockTiny2, TextName::WoodBlocks, Rect(457, 277, 41, 21));
	ImageMan::addImage(ImageName::WoodBlockTiny3, TextName::WoodBlocks, Rect(457, 299, 41, 21));
	ImageMan::addImage(ImageName::WoodBlockTiny4, TextName::WoodBlocks, Rect(457, 321, 41, 21));

	ImageMan::addImage(ImageName::WoodBlockMedThick, TextName::WoodBlocks, Rect(245, 81, 85, 42));
	ImageMan::addImage(ImageName::WoodBlockMedThick2, TextName::WoodBlocks, Rect(330, 81, 85, 42));
	ImageMan::addImage(ImageName::WoodBlockMedThick3, TextName::WoodBlocks, Rect(415, 81, 85, 42));
	ImageMan::addImage(ImageName::WoodBlockMedThick4, TextName::WoodBlocks, Rect(245, 124, 85, 42));

	ImageMan::addImage(ImageName::WoodBlockSquare, TextName::WoodBlocks, Rect(0, 336, 42, 42));
	ImageMan::addImage(ImageName::WoodBlockSquare2, TextName::WoodBlocks, Rect(85, 336, 42, 42));
	ImageMan::addImage(ImageName::WoodBlockSquare3, TextName::WoodBlocks, Rect(330, 125, 42, 42));
	ImageMan::addImage(ImageName::WoodBlockSquare4, TextName::WoodBlocks, Rect(374, 125, 42, 42));




	ImageMan::addImage(ImageName::GlassBlockShort, TextName::GlassBlocks, Rect(288, 346, 83, 21));
	ImageMan::addImage(ImageName::GlassBlockMed, TextName::GlassBlocks, Rect(288, 259, 168, 21));
	ImageMan::addImage(ImageName::GlassBlockLong, TextName::GlassBlocks, Rect(288, 215, 205, 21));

	ImageMan::addImage(ImageName::GlassBlockShort2, TextName::GlassBlocks, Rect(288, 368, 83, 21));
	ImageMan::addImage(ImageName::GlassBlockMed2, TextName::GlassBlocks, Rect(288, 281, 168, 21));
	ImageMan::addImage(ImageName::GlassBlockLong2, TextName::GlassBlocks, Rect(288, 192, 205, 21));

	ImageMan::addImage(ImageName::GlassBlockShort3, TextName::GlassBlocks, Rect(373, 346, 83, 21));
	ImageMan::addImage(ImageName::GlassBlockMed3, TextName::GlassBlocks, Rect(288, 302, 168, 21));
	ImageMan::addImage(ImageName::GlassBlockLong3, TextName::GlassBlocks, Rect(288, 236, 205, 21));

	ImageMan::addImage(ImageName::GlassBlockShort4, TextName::GlassBlocks, Rect(373, 368, 83, 21));
	ImageMan::addImage(ImageName::GlassBlockMed4, TextName::GlassBlocks, Rect(288, 324, 168, 21));
	ImageMan::addImage(ImageName::GlassBlockLong4, TextName::GlassBlocks, Rect(288, 169, 205, 21));

	ImageMan::addImage(ImageName::GlassBlockTinySquare, TextName::GlassBlocks, Rect(46, 336, 21, 21));
	ImageMan::addImage(ImageName::GlassBlockTinySquare2, TextName::GlassBlocks, Rect(45, 358, 21, 21));
	ImageMan::addImage(ImageName::GlassBlockTinySquare3, TextName::GlassBlocks, Rect(129, 336, 21, 21));
	ImageMan::addImage(ImageName::GlassBlockTinySquare4, TextName::GlassBlocks, Rect(129, 358, 21, 21));

	ImageMan::addImage(ImageName::GlassBlockMedThick, TextName::GlassBlocks, Rect(332, 81, 85, 42));
	ImageMan::addImage(ImageName::GlassBlockMedThick2, TextName::GlassBlocks, Rect(417, 81, 85, 42));
	ImageMan::addImage(ImageName::GlassBlockMedThick3, TextName::GlassBlocks, Rect(244, 126, 85, 42));
	ImageMan::addImage(ImageName::GlassBlockMedThick4, TextName::GlassBlocks, Rect(329, 126, 85, 42));




	ImageMan::addImage(ImageName::StoneBlockShort, TextName::StoneBlocks, Rect(416, 256, 83, 21));
	ImageMan::addImage(ImageName::StoneBlockMed, TextName::StoneBlocks, Rect(248, 256, 168, 21));
	ImageMan::addImage(ImageName::StoneBlockLong, TextName::StoneBlocks, Rect(248, 168, 205, 21));

	ImageMan::addImage(ImageName::StoneBlockShort2, TextName::StoneBlocks, Rect(248, 344, 83, 21));
	ImageMan::addImage(ImageName::StoneBlockMed2, TextName::StoneBlocks, Rect(248, 278, 168, 21));
	ImageMan::addImage(ImageName::StoneBlockLong2, TextName::StoneBlocks, Rect(248, 190, 205, 21));

	ImageMan::addImage(ImageName::StoneBlockShort3, TextName::StoneBlocks, Rect(332, 344, 83, 21));
	ImageMan::addImage(ImageName::StoneBlockMed3, TextName::StoneBlocks, Rect(248, 301, 168, 21));
	ImageMan::addImage(ImageName::StoneBlockLong3, TextName::StoneBlocks, Rect(248, 212, 205, 21));

	ImageMan::addImage(ImageName::StoneBlockShort4, TextName::StoneBlocks, Rect(417, 278, 83, 21));
	ImageMan::addImage(ImageName::StoneBlockMed4, TextName::StoneBlocks, Rect(248, 323, 168, 21));
	ImageMan::addImage(ImageName::StoneBlockLong4, TextName::StoneBlocks, Rect(248, 234, 205, 21));

	ImageMan::addImage(ImageName::StoneBlockMedThick, TextName::StoneBlocks, Rect(246, 82, 84, 42));
	ImageMan::addImage(ImageName::StoneBlockMedThick2, TextName::StoneBlocks, Rect(331, 82, 84, 42));
	ImageMan::addImage(ImageName::StoneBlockMedThick3, TextName::StoneBlocks, Rect(416, 82, 84, 42));
	ImageMan::addImage(ImageName::StoneBlockMedThick4, TextName::StoneBlocks, Rect(246, 82, 84, 42));

	ImageMan::addImage(ImageName::StoneCircle, TextName::StoneBlocks, Rect(169, 83, 75, 75));
	ImageMan::addImage(ImageName::StoneCircle2, TextName::StoneBlocks, Rect(169, 157, 75, 75));
	ImageMan::addImage(ImageName::StoneCircle3, TextName::StoneBlocks, Rect(169, 232, 75, 75));
	ImageMan::addImage(ImageName::StoneCircle4, TextName::StoneBlocks, Rect(169, 307, 75, 75));





	ImageMan::addImage(ImageName::Bang, TextName::Characters, Rect(674, 354, 87, 89));

	ImageMan::addImage(ImageName::SlingShotRight, TextName::Characters, Rect(0, 0, 38, 200));
	ImageMan::addImage(ImageName::SlingShotLeft, TextName::Characters, Rect(832, 0, 45, 125));
	ImageMan::addImage(ImageName::Sling, TextName::Sling, Rect(0, 0, 18, 23));

	ImageMan::addImage(ImageName::Egg, TextName::Characters, Rect(667, 819, 46, 58));
	ImageMan::addImage(ImageName::Trail, TextName::Characters, Rect(1005, 42, 40, 40));
}