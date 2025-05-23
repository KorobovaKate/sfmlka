#include <SceneList.h>
#include <FinishTrigger.h>

Scene* CreateSceneByNumber(int number)
{
	if (number == 1) return CreateLevel1();
	if (number == 2) return CreateLevel2();
	if (number == 3) return CreateLevel3();
	//...
}

Scene* CreateLevel1()
{
	Scene* scene = new Scene();

	scene->showColliders = true;
	Color bg(172, 233, 254);
	scene->backgroundColor = bg;

	scene->AddObject(GetGround1({ 10,767 }));
	scene->AddObject(GetGround3({ 943, 827 }));
	scene->AddObject(GetStar({ 1275, 650 }));
	scene->AddObject(GetStar({ 4250, 1081 }));
	scene->AddObject(GetWood1({ 4193, 1179 }));
	scene->AddObject(GetWood2({ 4452, 970 }));
	scene->AddObject(GetBox({ 3051, 990 }));
	scene->AddObject(GetGround7({ 4641, 760 }));
	scene->AddObject(GetFinishFlag({ 4994, 785 }, 2));
	scene->AddObject(GetPlayer({ 94, 761 }));
	scene->AddObject(GetHUD());
	
	return scene;
}

Scene* CreateLevel2()
{
	Scene* scene = new Scene();

	scene->showColliders = true;
	Color bg(172, 233, 254);
	scene->backgroundColor = bg;

	scene->AddObject(GetGround5({ 3, 1240 }));
	scene->AddObject(GetSpikes({ 430, 1761 }));
	scene->AddObject(GetSpikes({ 579, 1761 }));
	scene->AddObject(GetSpikes({ 1099, 1761 }));
	scene->AddObject(GetSpikes({ 1250, 1761 }));
	scene->AddObject(GetBox({ 735, 1622 }));
	scene->AddObject(GetBox({ 922, 1622 }));
	scene->AddObject(GetBox({ 922, 1447 }));
	scene->AddObject(GetGround2({ 1993, 1230 }));
	scene->AddObject(GetWood1({ 3990, 1485 }));
	scene->AddObject(GetWood1({ 4125, 1485 }));
	scene->AddObject(GetWood1({ 4838, 1485 }));
	scene->AddObject(GetWood1({ 4973, 1485 }));
	scene->AddObject(GetGround7({ 3378, 1360 }));
	scene->AddObject(GetGround7({ 4220, 1360 }));
	scene->AddObject(GetGround7({ 5062, 1360 }));

	scene->AddObject(GetEnemy({ 4472, 1455 }, 70, { 4067, 1455 }, { 4472, 1455 }));
	scene->AddObject(GetStar({ 4517, 1297 }));
	scene->AddObject(GetEnemy({ 4526, 1455 }, 70, { 4897, 1455 }, { 4526, 1455 }));
	scene->AddObject(GetPlayer({ 73, 1250 }));
	scene->AddObject(GetFinishFlag({ 5590, 1382 }, 3));
	scene->AddObject(GetHUD());

	return scene;
}

Scene* CreateLevel3()
{
	Scene* scene = new Scene();

	scene->showColliders = true;
	Color bg(172, 233, 254);
	scene->backgroundColor = bg;

	scene->AddObject(GetGround1({ 3, 1363 }));
	scene->AddObject(GetWood2({ 4398, 1614 }));
	scene->AddObject(GetWood3({ 5150, 1614 }));
	//scene->AddObject(wood3({ 5100, 1614 }));
	
	//scene->AddObject(wood2);
	scene->AddObject(GetGround7({ 4612, 1353 }));
	scene->AddObject(GetGround4({ 5758, 1509 }));
	scene->AddObject(GetGround3({ 6238, 1317}));
	scene->AddObject(GetGround6({ 7622, 1251 }));
	scene->AddObject(GetGround7({ 9584, 1245 }));
	scene->AddObject(GetSpikes({ 1558, 1732 }));
	scene->AddObject(GetSpikes({ 1918, 1732 }));
	scene->AddObject(GetSpikes({ 2014, 1732 }));
	scene->AddObject(GetSpikes({ 2364, 1732 }));

	scene->AddObject(GetWood1({ 1599, 1590 }));
	scene->AddObject(GetWood1({ 2308, 1590}));
	scene->AddObject(GetStar({ 2034, 1313 }));
	scene->AddObject(GetWood1({ 1839, 1500 }));
	scene->AddObject(GetWood1({ 2086, 1500 }));
	scene->AddObject(GetBox({ 3193, 1583 }));
	scene->AddObject(GetWood1({ 8634, 1554 }));
	scene->AddObject(GetWood1({ 8884, 1496 }));
	scene->AddObject(GetWood1({ 9142, 1423 }));

	scene->AddObject(GetSpikes({ 8538, 1845 }));
	scene->AddObject(GetSpikes({ 8722, 1845 }));
	scene->AddObject(GetSpikes({ 8905, 1845 }));
	scene->AddObject(GetSpikes({ 9082, 1845 }));
	scene->AddObject(GetSpikes({ 9255, 1845 }));
	
	//scene->AddObject(GetEnemy({ 400, 1465 }, 70, {200, 1465 }, {400, 1465 }));
	scene->AddObject(GetEnemy({ 1815, 1888 }, 0, { 1815, 1888 }, { 1815, 1888 }));
	scene->AddObject(GetEnemy({ 2269, 1888 }, 0, { 2269, 1888 }, { 2269, 1888 }));
	scene->AddObject(GetStar({ 6547, 1591 }));
	scene->AddObject(GetEnemy({ 6547, 1613 }, 90, { 6112, 1613 }, { 7001, 1613 }));
	scene->AddObject(GetPlayer({ 73, 1350 }));
	scene->AddObject(GetFinishFlag({ 9754, 1263 }, -1));
	scene->AddObject(GetHUD());

	return scene;
}

Scene* CreateGameOver()
{
	Scene* scene = new Scene();
	scene->showColliders = true;
	Color bg(172, 233, 254);
	scene->backgroundColor = bg;

	GameObject* ground = GetGround4({ 0, 150 });
	GameObject* boss = GetBoss({ 120, -20 }, 150, { 120, -20 }, { 120, -200 });
	ground->setScale(0.3, 0.3);
	boss->setScale(0.3, 0.3);
	scene->AddObject(ground);
	scene->AddObject(boss);
	scene->AddObject(GetGameOverPanel());
	Game::mainCamera->setCenter(0, 0);
	
	return scene;
}
