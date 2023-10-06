#include"GameEngine.h"

GameEngine::GameEngine()
{
	window.create(VideoMode(1500, 920), "Hibiscus_Flower");
	window.setFramerateLimit(100);

	resources.load();
	player = new Player(0, 460);
	NPC1 = new Player(0, 200);
	NPC2 = new Player(0, 310);
	NPC3 = new Player(0, 370);
	NPC4 = new Player(0, 580);
	NPC5 = new Player(0, 740);

	tagger.play();

	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setFillColor(Color::Black);
}

void GameEngine::handleMovement()
{
	if (!tagger.isSinging() and !tagger.isDetecting() and tagger.cnt == 0)
	{
		Sleep(1000);
		NPC1->SetNPCServive(10.0f);
		NPC2->SetNPCServive(15.0f);
		NPC3->SetNPCServive(20.0f);
		NPC4->SetNPCServive(25.0f);
		NPC5->SetNPCServive(30.0f);

		wait_time1 = 0;
		wait_time2 = 0;
		wait_time3 = 0;
		wait_time4 = 0;
		wait_time5 = 0;
		tagger.play();
	}

	NPC1->setSpeed(rand() % 80 / 10.0f);
	NPC2->setSpeed(rand() % 80 / 10.0f);
	NPC3->setSpeed(rand() % 100 / 10.0f);
	NPC4->setSpeed(rand() % 80 / 10.0f);
	NPC5->setSpeed(rand() % 100 / 10.0f);
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		player->move(6.0f, 0.0f);
		player->setMoving(true);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		player->move(0.0f, -4.0f);
		player->setMoving(true);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		player->move(0.0f, 4.0f);
		player->setMoving(true);
	}
	else
	{
		player->setMoving(false);
	}

	if (tagger.isSinging())
	{
		NPC1->setMoving(true);
		NPC2->setMoving(true);
		NPC3->setMoving(true);
		NPC4->setMoving(true);
		NPC5->setMoving(true);

		/*------------NPCs movemont---------------*/
		if ((NPC1->getCurPos_y() <= 180 and NPC1->getSpeed() - 4.f <= 0) or
			(NPC1->getCurPos_y() + 100 >= 920 and NPC1->getSpeed() - 4.f >= 0)) NPC1->move(NPC1->getSpeed(), (NPC1->getSpeed() - 4.f) * -1.0f);
		else NPC1->move(NPC1->getSpeed(), (NPC1->getSpeed() - 4.f));

		if ((NPC2->getCurPos_y() <= 180 and NPC2->getSpeed() - 4.f <= 0) or
			(NPC2->getCurPos_y() + 100 >= 920 and NPC2->getSpeed() - 4.f >= 0)) NPC2->move(NPC2->getSpeed(), (NPC2->getSpeed() - 4.f) * -1.0f);
		else NPC2->move(NPC2->getSpeed(), (NPC2->getSpeed() - 4.f));

		if ((NPC3->getCurPos_y() <= 180 and NPC3->getSpeed() - 5.f <= 0) or
			(NPC3->getCurPos_y() + 100 >= 920 and NPC3->getSpeed() - 5.f >= 0)) NPC3->move(NPC3->getSpeed(), (NPC3->getSpeed() - 5.f) * -1.0f);
		else NPC3->move(NPC3->getSpeed(), (NPC3->getSpeed() - 5.f));

		if ((NPC4->getCurPos_y() <= 180 and NPC4->getSpeed() - 4.f <= 0) or
			(NPC4->getCurPos_y() + 100 >= 920 and NPC4->getSpeed() - 4.f >= 0)) NPC4->move(NPC4->getSpeed(), (NPC4->getSpeed() - 4.f) * -1.0f);
		else NPC4->move(NPC4->getSpeed(), (NPC4->getSpeed() - 4.f));

		if ((NPC5->getCurPos_y() <= 180 and NPC5->getSpeed() - 5.f <= 0) or
			(NPC5->getCurPos_y() + 100 >= 920 and NPC5->getSpeed() - 5.f >= 0)) NPC5->move(NPC5->getSpeed(), (NPC5->getSpeed() - 5.f) * -1.0f);
		else NPC5->move(NPC5->getSpeed(), (NPC5->getSpeed() - 5.f));
	}
	else
	{
		if (NPC1->getNPCServive()) NPC1->setMoving(false);
		if (NPC2->getNPCServive()) NPC2->setMoving(false);
		if (NPC3->getNPCServive()) NPC3->setMoving(false);
		if (NPC4->getNPCServive()) NPC4->setMoving(false);
		if (NPC5->getNPCServive()) NPC5->setMoving(false);
	}

	if (NPC1->getCurPos_x() > 1250) NPC1->setFinished(true), NPC1->setMoving(true), NPC1->move(5.0f, 0.0f);
	if (NPC2->getCurPos_x() > 1250) NPC2->setFinished(true), NPC2->setMoving(true), NPC2->move(5.0f, 0.0f);
	if (NPC3->getCurPos_x() > 1250) NPC3->setFinished(true), NPC3->setMoving(true), NPC3->move(5.0f, 0.0f);
	if (NPC4->getCurPos_x() > 1250) NPC4->setFinished(true), NPC4->setMoving(true), NPC4->move(5.0f, 0.0f);
	if (NPC5->getCurPos_x() > 1250) NPC5->setFinished(true), NPC5->setMoving(true), NPC5->move(5.0f, 0.0f);
	if (player->getCurPos_x() > 1250) player->setFinished(true), player->setMoving(true), player->move(5.0f, 0.0f);
}

void GameEngine::render()
{
	Sprite PlayerSprite;
	Sprite NPCSprite1;
	Sprite NPCSprite2;
	Sprite NPCSprite3;
	Sprite NPCSprite4;
	Sprite NPCSprite5;
	Sprite TaggerSprite;
	Sprite BoomSprite;

	PlayerSprite = *Resources::get(Resources::Player, player->isMoving(), 0.1f);
	NPCSprite1 = *Resources::get(Resources::NPC_1, NPC1->isMoving(), 1 / NPC1->getSpeed() / 10.f);
	NPCSprite2 = *Resources::get(Resources::NPC_2, NPC2->isMoving(), 1 / NPC2->getSpeed() / 10.f);
	NPCSprite3 = *Resources::get(Resources::NPC_3, NPC3->isMoving(), 1 / NPC3->getSpeed() / 10.f);
	NPCSprite4 = *Resources::get(Resources::NPC_4, NPC4->isMoving(), 1 / NPC4->getSpeed() / 10.f);
	NPCSprite5 = *Resources::get(Resources::NPC_5, NPC5->isMoving(), 1 / NPC5->getSpeed() / 10.f);
	BoomSprite = *Resources::getBoom();

	/*------------------ Tagger Turning Algorithm -----------------*/
	if (!tagger.isSinging() and !tagger.isDetecting() and tagger.cnt > 0)
	{
		if (tagger.cnt == 4)
		{
			TaggerSprite = *Resources::get(Resources::Tagger, true, 0.0f);
		}
		TaggerSprite = *Resources::get(Resources::TaggerBack, true, 0.0f);
		tagger.cnt--;
	}
	else if (!tagger.isSinging() and tagger.cnt < 4)
	{
		tagger.detect.play();
		if (tagger.cnt == 0 and start_flg)
		{
			TaggerSprite = *Resources::get(Resources::TaggerBack, true, 0.0f);
		}
		TaggerSprite = *Resources::get(Resources::Tagger, true, 0.0f);
		tagger.cnt++;
		start_flg = true;
	}
	else if (tagger.isSinging())
	{
		TaggerSprite = *Resources::get(Resources::Tagger, false, 0.0f);
	}
	else
	{
		TaggerSprite = *Resources::get(Resources::TaggerBack, false, 0.0f);
	}

	PlayerSprite.setPosition(player->getCurPos_x(), player->getCurPos_y());
	NPCSprite1.setPosition(NPC1->getCurPos_x(), NPC1->getCurPos_y());
	NPCSprite2.setPosition(NPC2->getCurPos_x(), NPC2->getCurPos_y());
	NPCSprite3.setPosition(NPC3->getCurPos_x(), NPC3->getCurPos_y());
	NPCSprite4.setPosition(NPC4->getCurPos_x(), NPC4->getCurPos_y());
	NPCSprite5.setPosition(NPC5->getCurPos_x(), NPC5->getCurPos_y());
	TaggerSprite.setPosition(1380.f, 280.f);

	/*----------------Background-----------------*/
	Texture background;
	Sprite backgroundSprite;
	background.loadFromFile("images/background.png");
	backgroundSprite.setTexture(background);
	window.draw(backgroundSprite);

	RectangleShape line(Vector2f(700.0f, 5.0f));
	line.rotate(90.0f);
	line.setFillColor(Color::Black);
	line.setPosition(1300.0f, 260.0f);
	window.draw(line);

	text.setCharacterSize(70);
	text.setPosition(1400.f, 20.f);
	t = c.getElapsedTime();
	text.setString(to_string(45 - (int)t.asSeconds()));
	window.draw(text);

	/*-----------Catch------------------*/
	if (tagger.isDetecting())
	{
		if (NPC1->isMoving() and !NPC1->getNPCDead() and !NPC1->getFinished())
		{
			if (wait_time1 >= 30)
			{
				BoomSprite.setPosition(NPC1->getCurPos_x() - 65.0f, NPC1->getCurPos_y() - 150.0f);
				window.draw(BoomSprite);
				tagger.explosion.play();
				if (wait_time1 >= 50) NPC1->setNPCDead(true);
			}
			wait_time1++;
		}
		if (NPC2->isMoving() and !NPC2->getNPCDead() and !NPC2->getFinished())
		{
			if (wait_time2 >= 30)
			{
				BoomSprite.setPosition(NPC2->getCurPos_x() - 65.0f, NPC2->getCurPos_y() - 150.0f);
				window.draw(BoomSprite);
				tagger.explosion.play();
				if (wait_time2 >= 50) NPC2->setNPCDead(true);
			}
			wait_time2++;
		}
		if (NPC3->isMoving() and !NPC3->getNPCDead() and !NPC3->getFinished())
		{
			if (wait_time3 >= 30)
			{
				BoomSprite.setPosition(NPC3->getCurPos_x() - 65.0f, NPC3->getCurPos_y() - 150.0f);
				window.draw(BoomSprite);
				tagger.explosion.play();
				if (wait_time3 >= 50) NPC3->setNPCDead(true);
			}
			wait_time3++;
		}
		if (NPC4->isMoving() and !NPC4->getNPCDead() and !NPC4->getFinished())
		{
			if (wait_time4 >= 30)
			{
				BoomSprite.setPosition(NPC4->getCurPos_x() - 65.0f, NPC4->getCurPos_y() - 150.0f);
				window.draw(BoomSprite);
				tagger.explosion.play();
				if (wait_time4 >= 50) NPC4->setNPCDead(true);
			}
			wait_time4++;
		}
		if (NPC5->isMoving() and !NPC5->getNPCDead() and !NPC5->getFinished())
		{
			if (wait_time5 >= 30)
			{
				BoomSprite.setPosition(NPC5->getCurPos_x() - 65.0f, NPC5->getCurPos_y() - 150.0f);
				window.draw(BoomSprite);
				tagger.explosion.play();
				if (wait_time5 >= 50) NPC5->setNPCDead(true);
			}
			wait_time5++;
		}
		if (player->isMoving() and !player->getFinished())
		{
			BoomSprite.setPosition(player->getCurPos_x() - 65.0f, player->getCurPos_y() - 150.0f);
			window.draw(BoomSprite);
			tagger.explosion.play();
			player->setNPCDead(true);
		}
	}

	/*----------Timeout--------------*/
	if (45 - t.asSeconds() <= 0)
	{
		tagger.explosion.play();
		if (!NPC1->getNPCDead())
		{
			BoomSprite.setPosition(NPC1->getCurPos_x() - 65.0f, NPC1->getCurPos_y() - 150.0f);
			window.draw(BoomSprite);
		}
		if (!NPC2->getNPCDead())
		{
			BoomSprite.setPosition(NPC2->getCurPos_x() - 65.0f, NPC2->getCurPos_y() - 150.0f);
			window.draw(BoomSprite);
		}
		if (!NPC3->getNPCDead())
		{
			BoomSprite.setPosition(NPC3->getCurPos_x() - 65.0f, NPC3->getCurPos_y() - 150.0f);
			window.draw(BoomSprite);
		}
		if (!NPC4->getNPCDead())
		{
			BoomSprite.setPosition(NPC4->getCurPos_x() - 65.0f, NPC4->getCurPos_y() - 150.0f);
			window.draw(BoomSprite);
		}
		if (!NPC5->getNPCDead())
		{
			BoomSprite.setPosition(NPC5->getCurPos_x() - 65.0f, NPC5->getCurPos_y() - 150.0f);
			window.draw(BoomSprite);
		}
		BoomSprite.setPosition(player->getCurPos_x() - 65.0f, player->getCurPos_y() - 150.0f);
		window.draw(BoomSprite);
		player->setNPCDead(true);
	}

	/*-------------Game Over----------------*/
	if (player->getNPCDead())
	{
		BoomSprite.setPosition(player->getCurPos_x() - 65.0f, player->getCurPos_y() - 150.0f);
		window.draw(BoomSprite);
		if (Pwait_time > 20)
		{
			text.setCharacterSize(150);
			text.setPosition(380.f, 330.f);
			text.setString(String("You're Dead!"));
			window.draw(text);
			window.display();
			Sleep(3000);
			window.close();
		}
		window.draw(PlayerSprite);
		Pwait_time++;
	}

	/*-------------Cleared-------------------*/
	if (player->getCurPos_x() > 1530)
	{
		text.setCharacterSize(150);
		text.setPosition(430.f, 330.f);
		text.setString(String("Cleared!!"));
		window.draw(text);
		window.display();
		Sleep(3000);
		window.close();
	}

	if (!NPC1->getNPCDead()) window.draw(NPCSprite1);
	if (!NPC2->getNPCDead()) window.draw(NPCSprite2);
	if (!NPC3->getNPCDead()) window.draw(NPCSprite3);
	if (!NPC4->getNPCDead()) window.draw(NPCSprite4);
	if (!NPC5->getNPCDead()) window.draw(NPCSprite5);
	if (!player->getNPCDead()) window.draw(PlayerSprite);
	
	window.draw(TaggerSprite);
}

void GameEngine::loop()
{
	while (window.isOpen())
	{
		handleMovement();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		window.clear();
		render();
		window.display();
	}
}