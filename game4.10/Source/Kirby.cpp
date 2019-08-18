#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Kirby.h"
#include "BulletFactory.h"

namespace game_framework {
	Kirby::Kirby()
	{
	}

	Kirby::~Kirby()
	{
		delete kirby_normal;
		delete kirby_fire;
		delete kirby_spark;
		delete kirby_somethingInMouth;
	}

	int Kirby::GetX1()
	{
		return x;
	}

	int Kirby::GetY1()
	{
		return y;
	}

	int Kirby::GetX2()
	{
		return x + width;
	}

	int Kirby::GetY2()
	{
		return y + height;
	}

	int Kirby::GetType()
	{
		return type;
	}

	int Kirby::GetHeight()
	{
		return height;
	}

	int Kirby::GetWidth()
	{
		return width;
	}

	void Kirby::Initialize(int px, int py)
	{
		const int X_POS = px;
		const int Y_POS = py;
		x = X_POS;
		y = Y_POS;
		hp = 6;
		jumpDistance = 120;
		kickDistance = 100;
		exhaleDelay = 10;
		bullet = nullptr;
		bulletDistance = 0;
		InvincibleTime = 0;
		flyCount = 0;
		type = 0;
		eat = -1;
		velocity = 2;
		count = 0;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = isExhale = isJump = isAttack = isKick = isFly = isHurted = isSuck = isBig = isSwallow = isRunning = isInvincible = isLanding = false;
		isAlive = rightOrLeft = true;
		blood0.SetTopLeft(SIZE_X / 2 - blood0.Width() / 2, SIZE_Y - blood0.Height());
		blood1.SetTopLeft(SIZE_X / 2 - blood1.Width() / 2, SIZE_Y - blood1.Height());
		blood2.SetTopLeft(SIZE_X / 2 - blood2.Width() / 2, SIZE_Y - blood2.Height());
		blood3.SetTopLeft(SIZE_X / 2 - blood3.Width() / 2, SIZE_Y - blood3.Height());
		blood4.SetTopLeft(SIZE_X / 2 - blood4.Width() / 2, SIZE_Y - blood4.Height());
		blood5.SetTopLeft(SIZE_X / 2 - blood5.Width() / 2, SIZE_Y - blood5.Height());
		blood6.SetTopLeft(SIZE_X / 2 - blood6.Width() / 2, SIZE_Y - blood6.Height());

		kirby_normal = new Kirby_normal();
		kirby_fire = new Kirby_fire();
		kirby_spark = new Kirby_spark();
		kirby_somethingInMouth = new Kirby_somethingInMouth();
		kirbyType = kirby_normal;
	}

	bool Kirby::IsAlive()
	{
		return isAlive;
	}

	bool Kirby::IsFly()
	{
		return isFly;
	}

	bool Kirby::IsKick()
	{
		return isKick;
	}

	bool Kirby::IsSuck()
	{
		return isSuck;
	}

	bool Kirby::IsAttack()
	{
		return isAttack;
	}

	bool Kirby::IsRight()
	{
		return rightOrLeft;
	}

	bool Kirby::IsDown()
	{
		return isMovingDown;
	}

	bool Kirby::IsBig()
	{
		return isBig;
	}

	bool Kirby::IsMove()
	{
		return isMovingLeft || isMovingRight;
	}

	void Kirby::LoadBitmap()
	{
		GG.LoadBitmap(".\\RES\\Kirby\\Die.bmp", RGB(255, 255, 255));
		
		blood0.LoadBitmap(".\\RES\\Blood_0.bmp", RGB(255, 255, 255));
		blood1.LoadBitmap(".\\RES\\Blood_1.bmp", RGB(255, 255, 255));
		blood2.LoadBitmap(".\\RES\\Blood_2.bmp", RGB(255, 255, 255));
		blood3.LoadBitmap(".\\RES\\Blood_3.bmp", RGB(255, 255, 255));
		blood4.LoadBitmap(".\\RES\\Blood_4.bmp", RGB(255, 255, 255));
		blood5.LoadBitmap(".\\RES\\Blood_5.bmp", RGB(255, 255, 255));
		blood6.LoadBitmap(".\\RES\\Blood_6.bmp", RGB(255, 255, 255));

		lost.LoadBitmap();
	}

	void Kirby::OnMove(Map *m)
	{	
		//被攻擊且不是在空中也沒超出邊界時
		if (isHurted)
		{
			isFly = false;
			if (m->isEmpty(GetX2() - width / 2, GetY2() + 1))
				y++;
			if (rightOrLeft && m->isEmpty(GetX1() - STEP_SIZE, GetY1() + height / 2) && x - STEP_SIZE >= 0)
				x -= STEP_SIZE;
			else if (!rightOrLeft && m->isEmpty(GetX2() + STEP_SIZE, GetY2() - height / 2) && x + STEP_SIZE <= m->GetWidth() - width)
				x += STEP_SIZE;
		}
		else
		{
			if (isMovingLeft && !isSuck && !isSwallow && !isAttack)
			{
				rightOrLeft = false;        //設定面向左邊
				// 上坡
				if (m->isSlope(GetX1() - 1, GetY2()) && !isMovingDown && (isFly || !isMovingUp)) {
					if (isRunning && !isFly)
					{
						x -= STEP_SIZE * 2;
						y -= STEP_SIZE * 2;
					}
					else
					{
						x -= STEP_SIZE;
						y -= STEP_SIZE;
					}
				}
				// 下坡，前腳(左腳)離開斜坡(下方不是空的)就不要在下移了，不然會衝進土裡
				else if (m->isSlope(GetX2(), GetY2() + 1) && m->isEmpty(GetX1(), GetY2() + 1) && !isMovingDown && (isFly || !isMovingUp)) {
					if (isRunning && !isFly)
					{
						x -= STEP_SIZE * 2;
						y += STEP_SIZE * 2;
					}
					else
					{
						x -= STEP_SIZE;
						y += STEP_SIZE;
					}
				}
				//先判斷左邊是否可走且沒有按Down，狀態要是向左飛行中或正常向左走
				//為了防止變身後卡比變高導致牆壁失效，將判斷撞牆的點設在Y2-10
				else if (m->isEmpty(GetX1() - STEP_SIZE, GetY2() - 10) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x <= 0) //邊界
						x = 0;
					else if (isRunning && !isFly && !m->isEmpty(GetX1() + width / 2, GetY2() + 1))
						x -= STEP_SIZE * 2;
					else
						x -= STEP_SIZE;
				}
			}
			else if (isMovingRight && !isSuck && !isSwallow && !isAttack)
			{
				rightOrLeft = true;          //設定面向右邊
				// 上坡
				if (m->isSlope(GetX2() + 1, GetY2()) && !isMovingDown && (isFly || !isMovingUp)) {
					if (isRunning && !isFly)
					{
						x += STEP_SIZE * 2;
						y -= STEP_SIZE * 2;
					}
					else
					{
						x += STEP_SIZE;
						y -= STEP_SIZE;
					}
				}
				// 下坡，前腳(右腳)離開斜坡(下方不是空的)就不要在下移了，不然會衝進土裡
				else if (m->isSlope(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1) && !isMovingDown && (isFly || !isMovingUp)) {
					if (isRunning && !isFly)
					{
						x += STEP_SIZE * 2;
						y += STEP_SIZE * 2;
					}
					else
					{
						x += STEP_SIZE;
						y += STEP_SIZE;
					}
				}	
				//先判斷右邊是否可走且沒有按Down，狀態要是向右飛行中或正常向右走
				//為了防止變身後卡比變高導致牆壁失效，將判斷撞牆的點設在Y2-10
				else if (m->isEmpty(GetX2() + STEP_SIZE, GetY2() - 10) && !isMovingDown && (isFly || !isMovingUp))
				{
					if (x >= m->GetWidth() - width)  //邊界
						x = m->GetWidth() - width;
					else if (isRunning && !isFly && !m->isEmpty(GetX2() - width / 2, GetY2() + 1))
						x += STEP_SIZE * 2;
					else
						x += STEP_SIZE;
				}
			}
			if (isMovingUp && !isBig)
			{
				if (isFly && m->isEmpty_2(GetX1(), GetY1() - STEP_SIZE))  //判斷飛行中上面是否可走
				{
					if (y <= 0)  //邊界
						y = 0;
					else
						y -= STEP_SIZE;
				}
			}
			if (isJump && !isSuck)
			{
				if (jumpDistance == 120)
					CAudio::Instance()->Play(jump);
				jumpDistance -= 5;
				if (m->isEmpty_2(GetX1() + width / 2, GetY1() - 5) && y - 5 > 0)  //會不會撞到頭
					y -= 5;
				if (jumpDistance == 0 || y - 5 <= 0)
				{
					jumpDistance = 120;
					isJump = false;
				}
			}
		}

		if (!(isMovingUp || isJump) && m->isEmpty(GetX2() , GetY2() + 1) && m->isEmpty(GetX1(), GetY2() + 1))  //地吸引力
		{
			count++;
			isLanding = true;
			if (isFly)
				y += 1;	
			else
			{
				y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				if (velocity < 5 && count == 30)
				{
					velocity++; // 受重力影響，下次的下降速度增加
					count = 0;
				}
			}
		}
		else if (!isFly && m->isEmpty(x, y + height + 1) && m->isEmpty(x + width, y + height + 1))  // 當y座標還沒碰到地板
			y += 1;
		else
		{
			if (isLanding == true && !isFly)
			{
				CAudio::Instance()->Play(landing);
				isLanding = false;
			}
			velocity = 2; // 重設重力加速度
			count = 0;
		}
	}

	void Kirby::OnShow(Map *m)
	{
		height = kirbyType->GetHeight();
		width = kirbyType->GetWidth();

		if (hp == 6) blood6.ShowBitmap();
		else if (hp == 5) blood5.ShowBitmap();
		else if (hp == 4) blood4.ShowBitmap();
		else if (hp == 3) blood3.ShowBitmap();
		else if (hp == 2) blood2.ShowBitmap();
		else if (hp == 1) blood1.ShowBitmap();
		else blood0.ShowBitmap();

		if (InvincibleTime != 0) InvincibleTime--;
		else isInvincible = false;

		ShowKirby(m);

		if (lost.IsAlive())
		{
			lost.OnMove(m, x, y, isSuck);
			lost.OnShow(m);
		}
	}

	void Kirby::Hurted(Map *m)
	{
		if (type != 0)
		{
			lost.Initialize(type, x, y);
			kirbyType = kirby_normal;
			type = 0;
		}

		if (!isInvincible)
		{
			hp--;
			isInvincible = true;
			InvincibleTime = 60;
			if(hp>0)
				CAudio::Instance()->Play(hurted);
		}

		if (hp > 0)
			isHurted = true;
		else
		{
			CAudio::Instance()->Play(die);
			CAudio::Instance()->Stop(AUDIO_BACKGROUND);
			isAlive = false;
		}
	}

	void Kirby::Die(Map *m)
	{
		GG.SetTopLeft(m->ScreenX(x), m->ScreenY(y));
		GG.ShowBitmap();
		y -= 3;
	}

	void Kirby::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Kirby::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Kirby::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Kirby::SetMovingUp(bool flag)
	{
		if (isBig)
			isMovingUp = false;
		else
			isMovingUp = flag;
	}

	void Kirby::SetJump(bool flag)
	{
		isJump = flag;
	}

	void Kirby::SetAttack(bool flag)
	{
		isAttack = flag;
	}

	void Kirby::SetSuck(bool flag)
	{
		isSuck = flag;
	}

	void Kirby::SetBig(bool flag)
	{
		isBig = flag;
		if (flag)
			kirbyType = kirby_somethingInMouth;
		else
			kirbyType = kirby_normal;
	}

	void Kirby::SetRun(bool flag) {
		isRunning = flag;
	}

	void Kirby::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Kirby::Restore()
	{
		hp = 6;
	}

	void Kirby::SetEat(int t)
	{
		eat = t;
	}

	Bullet* Kirby::GetBullet()
	{
		return bullet;
	}

	void Kirby::DeleteBullet()
	{
		delete bullet;
		bullet = nullptr;
	}

	void Kirby::Attack(Map *m)
	{
		//------空氣彈------
		if (isFly && isAttack)
		{
			NewBulletFactory* gasFactory = new NewBulletFactory;
			bullet = gasFactory->CreateBullet();
			bullet->LoadBitmap();
			bullet->SetXY(x, y);
			bulletDistance = 176;
			bulletDirection = rightOrLeft;
			isFly = false;
		}
		if (bulletDistance != 0 && bullet != nullptr)
		{
			bulletDistance -= STEP_SIZE * 2;
			bullet->OnMove(m, bulletDirection);
			bullet->OnShow(m);
		}
		else
			DeleteBullet();

		//------星星------
		if (isBig && isAttack && !isSuck)
		{
			StarFactory* starFactory = new StarFactory;
			bullet = starFactory->CreateBullet();
			bullet->LoadBitmap();
			bullet->SetXY(x, y);
			bulletDistance = 376;
			bulletDirection = rightOrLeft;
		}
		if (bulletDistance != 0 && bullet != nullptr)
		{
			bulletDistance -= STEP_SIZE * 2;
			bullet->OnMove(m, bulletDirection);
			bullet->OnShow(m);
		}
		else
			DeleteBullet();

		//------踢擊------
		if (!isFly && !isBig && (isMovingDown || isKick) && (isAttack || isKick) && !m->isEmpty(GetX2() - width / 2, GetY2() + 1)) //在地面上蹲下按攻擊
		{
			isKick = true;
			isAttack = false;
			kickDistance -= 5;
			if (rightOrLeft && m->isEmpty(GetX2() + 5, GetY2() - 5) && x + 5 <= m->GetWidth() - 68)  //右邊會不會踢牆(y-5是補償卡比大小)，68是卡比右踢圖片寬度
				x += 5;
			else if (!rightOrLeft && m->isEmpty(GetX1() - 5, GetY2() - 5) && x - 5 >= 0)  //左邊會不會踢牆(y-5是補償卡比大小)
				x -= 5;
			//踢完.踢到邊界.腳沒踏到地都不能使用踢擊
			if (kickDistance == 0 || x <= 0 || x >= m->GetWidth() || m->isEmpty(GetX2() - width / 2, GetY2() + 1))
			{
				kickDistance = 100;
				isKick = false;
			}
		}
	}

	void Kirby::Transform()
	{
		if (eat == 1)
		{
			type = 1;
			y -= 40;
			kirbyType = kirby_spark;
		}
		else if (eat == 2)
		{
			type = 2;
			y -= 40;
			kirbyType = kirby_fire;
		}
	}

	void Kirby::ShowKirby(Map* m)
	{
		kirby_normal->SetPoint(x, y, m);
		kirby_fire->SetPoint(x, y, m);
		kirby_spark->SetPoint(x, y, m);
		kirby_somethingInMouth->SetPoint(x, y, m);

		Attack(m);

		if (!isMovingUp && !isFly)   //沒吸氣也沒飛行就要reset吸氣動畫
		{
			kirbyType->ResetMove(KirbyType::MovingType::prepareFlyR);
			kirbyType->ResetMove(KirbyType::MovingType::prepareFlyL);
		}

		if (isHurted)   // 被攻擊
		{
			SetBig(false);
			kirbyType->SetPoint(x, y, m);
			if (rightOrLeft)
				kirbyType->OnShow(KirbyType::MovingType::hurtedR);
			else
				kirbyType->OnShow(KirbyType::MovingType::hurtedL);

			if(kirbyType->ResetMove(KirbyType::MovingType::hurtedL) || kirbyType->ResetMove(KirbyType::MovingType::hurtedR))
				isHurted = false;
		}
		else if (isBig)
		{
			if (isSuck)
				isAttack = false;
			if (isJump)   //跳躍
			{
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::jumpR);
				else
					kirbyType->OnShow(KirbyType::MovingType::jumpL);
			}
			// || (bulletDistance < 376 && bulletDistance > 346)是為了讓吐怪的圖能顯示久一點到大概1秒(每秒跑30次OnShow迴圈)
			else if (isAttack || (bulletDistance < 376 && bulletDistance > 346))  //吐怪
			{
				// isAttack要設為false，避免吐怪完馬上吸怪的bug
				isAttack = false;
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::threwR);
				else
					kirbyType->OnShow(KirbyType::MovingType::threwL);
				// 在吐氣的圖顯示結束前將卡比變回原形
				if (bulletDistance <= 350)
					SetBig(false);
			}
			else if (isSwallow || (isMovingDown && (!m->isEmpty(GetX1(), GetY2() + 1) || !m->isEmpty(GetX2(), GetY2() + 1))))   //吞食
			{
				isSwallow = true;
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::swallowR);
				else
					kirbyType->OnShow(KirbyType::MovingType::swallowL);
				if (kirbyType->ResetMove(KirbyType::MovingType::swallowR) || kirbyType->ResetMove(KirbyType::MovingType::swallowL))
				{
					isSwallow = false;
					SetBig(false);
					Transform();
				}
			}
			//自由落體
			//兩腳地都必須空，且不是走在斜坡，才會顯示降落的圖
			else if (!isFly && m->isEmpty(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1) && !m->isSlope(GetX1(), GetY2() + 11) && !m->isSlope(GetX2(), GetY2() + 11))
			{
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::landingR);
				else
					kirbyType->OnShow(KirbyType::MovingType::landingL);
			}
			else if (isMovingLeft)   //向左走
				kirbyType->OnShow(KirbyType::MovingType::goL);
			else if (isMovingRight)  //向右走
				kirbyType->OnShow(KirbyType::MovingType::goR);
			else if (rightOrLeft)   //面相右
				kirbyType->OnShow(KirbyType::MovingType::originR);
			else if (!rightOrLeft)  //面相左
				kirbyType->OnShow(KirbyType::MovingType::originL);
		}
		else
		{
			if (isAttack && !isFly && !isMovingDown)  //吸怪
			{
				if(type == 0) isSuck = true;
				if (rightOrLeft)
				{
					kirbyType->OnShow(KirbyType::MovingType::suckR);
				}
				else
				{
					kirbyType->OnShow(KirbyType::MovingType::suckL);
				}
				if (lost.IsAlive() && (lost.GetX() - x >= -2) && (lost.GetX() - x <= 2) && (lost.GetY() - y >= -2) && (lost.GetY() - y <= 2) && type == 0)
				{
					lost.SetAlive(false);
					SetBig(true);
					SetEat(lost.type);
				}
			}
			else if (isJump)   //跳躍
			{
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::jumpR);
				else
					kirbyType->OnShow(KirbyType::MovingType::jumpL);
			}
			else if ((isAttack || isExhale) && isFly)   //吐氣
			{
				// isAttack要設為false，避免吐氣完馬上吸怪的bug
				isAttack = false;
				isExhale = true;
				exhaleDelay--;
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::exhaleR);
				else
					kirbyType->OnShow(KirbyType::MovingType::exhaleL);
				if (exhaleDelay == 0)
				{
					exhaleDelay = 10;
					kirbyType->ResetMove(KirbyType::MovingType::prepareFlyR);
					kirbyType->ResetMove(KirbyType::MovingType::prepareFlyL);
					isFly = false;
					isExhale = false;
				}
				SetEat(-1);
			}
			else if (isMovingUp)
			{
				if (kirbyType->ResetMove(KirbyType::MovingType::prepareFlyR) || kirbyType->ResetMove(KirbyType::MovingType::prepareFlyL) || isFly)   //飛行前吸氣
				{
					isFly = true;
					flyCount++;
					if (flyCount == 1)
						CAudio::Instance()->Play(fly);
					else if (flyCount == 60)
						flyCount = 0;

					if (rightOrLeft)
						kirbyType->OnShow(KirbyType::MovingType::flyR);
					else
						kirbyType->OnShow(KirbyType::MovingType::flyL);
				}
				else
				{
					if (rightOrLeft)
					{
						kirbyType->OnShow(KirbyType::MovingType::prepareFlyR);
					}
					else
					{
						kirbyType->OnShow(KirbyType::MovingType::prepareFlyL);
					}
				}
			}
			else if (isFly)  //沒按上但飛行中
			{
				flyCount++;
				if (flyCount == 1)
					CAudio::Instance()->Play(fly);
				else if (flyCount == 60)
					flyCount = 0;
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::flyR);
				else
					kirbyType->OnShow(KirbyType::MovingType::flyL);
			}
			//自由落體
			//兩腳地都必須空，且不是走在斜坡，才會顯示降落的圖
			else if (!isFly && m->isEmpty(GetX1(), GetY2() + 1) && m->isEmpty(GetX2(), GetY2() + 1) && !m->isSlope(GetX1(), GetY2() + 11) && !m->isSlope(GetX2(), GetY2() + 11))
			{
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::landingR);
				else
					kirbyType->OnShow(KirbyType::MovingType::landingL);
			}
			else if (isKick && !isFly)   //踢擊
			{
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::downAttackR);
				else
					kirbyType->OnShow(KirbyType::MovingType::downAttackL);
			}
			else if (isMovingDown && !m->isEmpty(GetX1() + width / 2, GetY2() + 1))   //縮小
			{
				if (rightOrLeft)
					kirbyType->OnShow(KirbyType::MovingType::downR);
				else
					kirbyType->OnShow(KirbyType::MovingType::downL);
			}
			else if (!isFly && isRunning && (isMovingLeft || isMovingRight))  //跑
			{
				if (!rightOrLeft)
				{
					kirbyType->OnShow(KirbyType::MovingType::runL);
				}
				else
				{
					kirbyType->OnShow(KirbyType::MovingType::runR);
				}
			}
			else if (!isFly && isMovingLeft)   //一般向左走
			{
				kirbyType->OnShow(KirbyType::MovingType::goL);
			}
			else if (!isFly && isMovingRight)   //一般向右走
			{
				 kirbyType->OnShow(KirbyType::MovingType::goR);
			}
			else if (rightOrLeft)   //面相右
				kirbyType->OnShow(KirbyType::MovingType::originR);
			else if (!rightOrLeft)  //面相左
				kirbyType->OnShow(KirbyType::MovingType::originL);
		}
	}
}