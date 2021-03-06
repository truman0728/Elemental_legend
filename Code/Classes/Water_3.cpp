//
//  Water_3.cpp
//  NewGame
//
//  Created by 胡可 on 15/10/12.
//
//

#include "Water_3.h"
#include "ResourceSystem.h"
#include "BattleSystem.h"
#include "AttrSystem.h"


Water_3::Water_3()
{
    isCheck = false;
    _time = 3;
    _touchMax = 1;
    _NeedRes = 2;
    timeMax = 3;
}



Water_3::~Water_3()
{
    
}

bool Water_3::Cast(cocos2d::Layer *_tag, const cocos2d::Vec2 _pos, int& _num)
{
    _NeedRes = AttrSystem::getInstance()->GetBaseAttr(ATTR_TYPE::ATTR_MAGIC)*0.03f * (1 - BattleSystem::getInstance()->getPlayer()->GetReduceMagic());
    TouchTimes = _num;
    if(TouchTimes == 1)
    {
        int NeedMagic = BattleSystem::getInstance()->getPlayer()->getState()->GetMpMax()*CHANGE_MAGIC_VALUE + _NeedRes;
        if(BattleSystem::getInstance()->getPlayer()->getState()->GetMP() >= NeedMagic)
        {
            ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, NeedMagic - _NeedRes);
        }
        else
        {
            return false;
        }
    }
    if(BattleSystem::getInstance()->getPlayer()->getState()->GetMP() < _NeedRes)
    {
        return false;
    }
    AudioSystem::getInstance()->PlayEffectAudio(EFFECT_AUDIO_LIST::EFFECT_WATER_01);
    cocos2d::ParticleSystem* _particleAnimation = cocos2d::ParticleSystemQuad::create("particle/water_particle_plist.plist");
    _particleAnimation->setAutoRemoveOnFinish(true);
    _particleAnimation->setPosition(_pos);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER, MAGIC, REDUCE, _NeedRes);
    ResourceSystem::getInstance()->UpdateResourceBar(PLAYER,HEALTH, ADD, BattleSystem::getInstance()->getPlayer()->getState()->GetReHp()*1.2f);
    if(isCheck == false)
    {
        _time = timeMax;
        isCheck = true;
        BattleSystem::getInstance()->getPlayer()->getState()->UpdateDefence(AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_DEF)*0.3f);
        _tag->schedule(std::bind([=]
                                 {
                                     _time--;
                                    if(_time <= 0)
                                     {
                                         
                                     BattleSystem::getInstance()->getPlayer()->getState()->UpdateDefence(-AttrSystem::getInstance()->GetRealAttr(ATTR_TYPE::ATTR_DEF)*0.3f);
                                     isCheck = false;
                                    _tag->unschedule("Water_3");
                                     }
                                 }), 1, "Water_3");
    }
    else if(isCheck == true)
    {
        _time = timeMax;;
    }
    _tag->addChild(_particleAnimation);
    return true;
}