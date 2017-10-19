#include "Arduino.h"
#include "CPProbotlib.h"

RobotCommand::RobotCommand(int right_frontPower, int left_frontPower, int right_backPower, int left_backPower, int right_Power, int left_Power)
{
	//右タイヤ
	pinMode(6,OUTPUT);
	pinMode(7,OUTPUT);

	//左タイヤ
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);

  //前進関数のブースト
	frontPower_r = right_frontPower;
	frontPower_l = left_frontPower;

	/*後退関数のブースト*/
	backPower_r = right_backPower;
	backPower_l = left_backPower;

	//左回転関数のブースト
	power_r = right_Power;

	//右回転関数のブースト
	power_l = left_Power;
}

//前進
void RobotCommand::front(int time)
{
	//右タイヤ
	digitalWrite(6,HIGH);
	digitalWrite(7,LOW);

	//左タイヤ
	digitalWrite(8,LOW);
	digitalWrite(9,HIGH);

	//出力調整
	analogWrite(3,val + frontPower_r);
	analogWrite(5,val + frontPower_l);

  delay(time);

  back(100);
}

//後退
void RobotCommand::back(int time)
{
	//右タイヤ
	digitalWrite(6,LOW);
	digitalWrite(7,HIGH);

	//左タイヤ
	digitalWrite(8,HIGH);
	digitalWrite(9,LOW);

	//出力調整
	analogWrite(3,val + backPower_r);
	analogWrite(5,val + backPower_l);

  delay(time);
}

//左回転
void RobotCommand::left(int time)
{
	//右タイヤ
	digitalWrite(6,HIGH);
	digitalWrite(7,LOW);

	//左タイヤ
	digitalWrite(8,LOW);
	digitalWrite(9,LOW);

	//出力調整
	analogWrite(3,val + power_r);
	analogWrite(5,val);

  delay(time);
}

//右回転
void RobotCommand::right(int time)
{
	//右タイヤ
	digitalWrite(6,LOW);
	digitalWrite(7,LOW);

	//左タイヤ
	digitalWrite(8,LOW);
	digitalWrite(9,HIGH);

	//出力調整
	analogWrite(3,val);
	analogWrite(5,val + power_l);

  delay(time);
}

//停止
void RobotCommand::wait(int time)
{
	//右回転
	digitalWrite(6,LOW);
	digitalWrite(7,LOW);

	//左回転
	digitalWrite(8,LOW);
	digitalWrite(9,LOW);

  delay(time);
}