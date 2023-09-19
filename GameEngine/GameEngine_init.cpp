#include "../Code/GameEngine.h"

void GameEngine::initClassEnemy() {
    this->enemyLvL[1] = {
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 2200, 1236, 65, 55, "Bat"),
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 2250, 1236, 65, 55, "Bat"),
//            new Enemy_Ghost(config->s_EnemyGhost->s, gameLvL, 800, 1236, 40, 88, "Ghost"),
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 9800, 1236, 65, 55, "Bat"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 9000, 1800, 50, 50, "Boom"),
//            new Enemy_BigGhost(config->s_Enemy_BigGhost->s, gameLvL, 800, 1236, 65, 125, "BigGhost"),
//            new Enemy_Mag(config->s_Enemy_Mag->s,enemyMagDamage, gameLvL, 800, 1236, 40, 110, "Mag"),
    };
    //enemy lvl 2
    this->enemyLvL[2] = {
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 7500, 1236, 65, 55, "Bat"),
            new Enemy_Ghost(config->s_enemy_ghost->s, gameLvL, 7800, 1236, 40, 88, "Ghost"),
            new Enemy_Mag(config->s_enemy_mag->s, enemyMagDamage, gameLvL, 8000, 1236, 40, 110, "Mag"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 7800, 1236, 50, 50, "Boom"),
    };
    // enemy lvl 3
    this->enemyLvL[3] = {
            new Enemy_Bat(config->s_enemy_bat->s, gameLvL, 11250, 1236, 65, 55, "Bat"),
            new Enemy_Ghost(config->s_enemy_ghost->s, gameLvL, 7761, 1890, 40, 88, "Ghost"),
            new Enemy_Ghost(config->s_enemy_ghost->s, gameLvL, 8805, 1890, 40, 88, "Ghost"),
            new Enemy_BigGhost(config->s_enemy_BigGhost->s, gameLvL, 5010, 2418, 65, 125, "BigGhost"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 5010, 2418, 2626, 50, "Boom"),
            new Enemy_Boom(config->s_enemy_boom->s, gameLvL, 865, 2404, 2626, 50, "Boom"),
    };
    // enemy lvl 4
    this->enemyLvL[4] = {
            new Enemy_Bat(config->s_enemy_bat_heavenly->s, gameLvL, 1200, 1236, 65, 55, "Bat"),
            new Enemy_Ghost(config->s_enemy_ghost_heavenly->s, gameLvL, 1161, 1230, 40, 88, "Ghost"),
            new Enemy_BigGhost(config->s_enemy_BigGhost_heavenly->s, gameLvL, 1010, 1218, 65, 125, "BigGhost"),
    };
    // enemy lvl 5
    this->enemyLvL[5] = {

    };
    // enemy lvl 6
    this->enemyLvL[6] = {

    };
}
void GameEngine::initClassNps() {
    this->npsLvL[1] = {
            new Knight(config->s_nps_knight->s, gameLvL, config->text_nps_knight, 9500, 586, 56, 138, "Knight"),
            new Historian(config->s_nps_historian->s, gameLvL, config->text_nps_historian, 1100, 1520, 156, 150, "Historian"),
            new Blacksmith(config->s_nps_blacksmith->s, gameLvL, config->text_nps_blacksmith, 5750, 1620, 122, 152, "Blacksmith"),
    };
    // nps lvl 2
    this->npsLvL[2] = {
            new Aiden(config->s_nps_aiden->s, gameLvL, config->text_nps_aiden, 4550, 1620, 50, 105, "Aiden"),
            new Blacksmith(config->s_nps_blacksmith->s, gameLvL, config->text_nps_blacksmith, 1000, 1620, 50, 152, "Blacksmith"),
            new Witcher(config->s_nps_witcher->s, gameLvL, config->text_nps_witcher, 800, 1620, 50, 190, "Witcher"),
    };
    // nps lvl 3
    this->npsLvL[3] = {
            new Supreme_Wizard(config->s_nps_SupremeWizard->s, gameLvL, config->text_nps_supreme_wizard, 1250, 1620, 122, 152, "Supreme_Wizard"),
            new Blacksmith(config->s_nps_blacksmith->s, gameLvL, config->text_nps_blacksmith, 1100, 1250, 122, 152, "Blacksmith"),
            new Soothsayer(config->s_nps_soothsayer->s, gameLvL, config->text_nps_soothsayer, 2000, 1250, 122, 152, "Soothsayer"),
            new Swordsman(config->s_nps_swordsman->s, gameLvL, config->text_nps_swordsman, 1727, 2460, 122, 152, "Swordsman"),
    };
    // nps lvl 4
    this->npsLvL[4] = {

    };
    // nps lvl 5
    this->npsLvL[5] = {

    };
    // nps lvl 6
    this->npsLvL[6] = {

    };
}
void GameEngine::initClassChest() {
    this->chestLvL[1] = {
            new Chest(config->s_chest_small->s, gameLvL, 1000, 1600, 65, 70, "SmallChest"),
//            new Chest(config->s_chest_middle->s, gameLvL, 1200, 1600, 65, 82, "MiddleChest"),
//            new Chest(config->s_chest_big->s, gameLvL, 1400, 1600, 65, 90, "BigChest"),
            //
            new Chest(config->s_chest_small->s, gameLvL, 9790, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_chest_small->s, gameLvL, 5903, 1600, 65, 70, "SmallChest"),
            new Chest(config->s_chest_middle->s, gameLvL, 570, 1248, 65, 82, "MiddleChest"),
            new Chest(config->s_chest_big->s, gameLvL, 3026, 1100, 65, 90, "BigChest"),
    };
    //Chest lvl 2
    this->chestLvL[2] = {
            new Chest(config->s_chest_small->s, gameLvL, 3410, 1500, 65, 70, "SmallChest"),
            new Chest(config->s_chest_big->s, gameLvL, 2250, 1500, 65, 90, "BigChest"),
    };
    //Chest lvl 3
    this->chestLvL[3] = {
            new Chest(config->s_chest_big->s, gameLvL, 8142, 2562, 65, 90, "BigChest"),
    };
    //Chest lvl 4
    this->chestLvL[4] = {

    };
    //Chest lvl 5
    this->chestLvL[5] = {

    };
    //Chest lvl 6
    this->chestLvL[6] = {

    };
}
void GameEngine::initClassObject() {
    this->objLvL[1] = {
            new Object(config->s_obj_stove->s, gameLvL, 5650, 1600, 92, 108, "Stove"),
            new Object(config->s_obj_HomeDrov->s, gameLvL, 1200, 1600, 100, 298, "Home"),
            new Object(config->s_obj_TableHouse->s, gameLvL, 9520, 1600, 400, 296, "TableHouse"),
    };
    // Object LvL 2
    this->objLvL[2] = {
            new Object(config->s_obj_BushHouse->s, gameLvL, 4500, 1600, 500, 300, "BushHouse"),
            new Object(config->s_obj_BonfireHouse->s, gameLvL, 2800, 1600, 1250, 410, "BonfireHouse"),
    };
    // Object LvL 3
    this->objLvL[3] = {
            new Object(config->s_obj_FlyingObelisk->s, gameLvL, 1400, 1600, 145, 390, "FlyingObelisk"),
            new Object(config->s_obj_DarkTreeBig->s, gameLvL, 1450, 1600, 125, 265, "DarkTreeBig"),
            new Object(config->s_obj_DarkTreeSmall->s, gameLvL, 1450, 1600, 125, 265, "DarkTreeSmall"),
            //RemainsSkeleton
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 1500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 2400, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 3300, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 3500, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 3700, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 4700, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 5100, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 5400, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 5700, 1600, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 6200, 1600, 95, 72, "RemainsSkeleton"),

            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 7761, 1890, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 8805, 1890, 95, 72, "RemainsSkeleton"),
            new Object(config->s_obj_RemainsSkeleton->s, gameLvL, 5010, 2418, 95, 72, "RemainsSkeleton"),
    };
    // Object LvL 4
    this->objLvL[4] = {

    };
    // Object LvL 5
    this->objLvL[5] = {

    };
    // Object LvL 6
    this->objLvL[6] = {

    };
}
void GameEngine::initClassItem() {
    this->itemLvL[1] = {
            new equipment_item(config->s_item_sword[2]->s, gameLvL, 6858, 1900, 30, 25, "SwordRed"),
            new equipment_item(config->s_item_shield[2]->s, gameLvL, 11473, 1800, 30, 65, "ShieldRed"),
//            new equipment_item(config->s_item_sword[3]->s, gameLvL, 1100, 1600, 30, 25, "SwordGreen"),
//            new equipment_item(config->s_item_sword[4]->s, gameLvL, 6850, 244, 30, 25, "SwordBrow"),

//            new equipment_item(config->s_item_shield[3]->s, gameLvL, 1300, 1600, 30, 65, "ShieldGreen"),
//            new equipment_item(config->s_item_shield[4]->s, gameLvL, 6820, 244, 30, 65, "ShieldBrow"),

            new health_item(config->s_item_health->s, gameLvL, 4800, 1600, 40, 45, "Health"),
            new money_item(config->s_item_money->s, gameLvL, 300, 1600, 30, 40, "Money"),
            new money_item(config->s_item_diamond->s, gameLvL, 9400, 1600, 40, 60, "Diamond"),
            new money_item(config->s_item_diamond->s, gameLvL, 6820, 244, 40, 60, "Diamond"),
            new key_item(config->s_item_KeySilver->s, gameLvL, 8, 1600, 40, 45, "KeySilver"),
            new key_item(config->s_item_KeyGold->s, gameLvL, 9300, 1600, 40, 45, "KeyGold"),
            new key_item(config->s_item_KeyGold->s, gameLvL, 6830, 244, 40, 45, "KeyGold"),

            new Particle_of_Strength_item(config->s_particle_of_strength_sprint->s, gameLvL, 2000, 1600, 40, 40, "Sprint"),
            new Particle_of_Strength_item(config->s_particle_of_strength_shoot->s, gameLvL, 2100, 1600, 40, 40, "Shoot"),
            new Particle_of_Strength_item(config->s_particle_of_strength_shoot->s, gameLvL, 2200, 1600, 40, 40, "Repulsion"),
            new Particle_of_Strength_item(config->s_particle_of_strength_shoot->s, gameLvL, 2300, 1600, 40, 40, "Speed"),
            new Particle_of_Strength_item(config->s_particle_of_strength_shoot->s, gameLvL, 2400, 1600, 40, 40, "Jump"),
    };
    // item lvl 2
    this->itemLvL[2] = {
            new money_item(config->s_item_money->s, gameLvL, 4000, 1200, 30, 40, "Money"),
            new health_item(config->s_item_health->s, gameLvL, 2000, 1200, 40, 45, "Health"),
            new key_item(config->s_item_KeySilver->s, gameLvL, 550, 1200, 40, 45, "KeySilver"),
            new key_item(config->s_item_KeyGold->s, gameLvL, 4550, 1200, 40, 45, "KeyGold"),
    };
    // item lvl 3
    this->itemLvL[3] = {
            new key_item(config->s_item_KeySilver->s, gameLvL, 8142, 2562,40, 45, "KeySilver"),
    };
    // item lvl 4
    this->itemLvL[4] = {

    };
    // item lvl 5
    this->itemLvL[5] = {

    };
    // item lvl 6
    this->itemLvL[6] = {

    };
}
void GameEngine::initClassFon() {
    this->fonLvL[1] = {
            new FonGame(config->s_LvL_Fon[1]->s, gameLvL, 0, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL_Fon[1]->s, gameLvL, 4900, 1360, 10, 10,"Fon"),
            new FonGame(config->s_LvL_FonBack[1]->s, gameLvL, 0, 1860, 0, 0, "Back"),
            new FonGame(config->s_LvL_FonBack[1]->s, gameLvL, 4900, 1860, 0, 0, "Back")
    };
    // Fon lvl 2
    this->fonLvL[2] = {
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 0, 1360, 10, 10," "),
//            new FonGame(config->s_LvL2_Fon->s, gameLvL, 4900, 1360, 10, 10," ")
    };
    // Fon lvl 3
    this->fonLvL[3] = {

    };
    // Fon lvl 4
    this->fonLvL[4] = {

    };
    // Fon lvl 5
    this->fonLvL[5] = {

    };
    // Fon lvl 6
    this->fonLvL[6] = {

    };
}
void GameEngine::initClassCloud()  {
    cloudLvL[1] = {
            new Cloud(config->s_Cloud_ainm->s, gameLvL, 0,  100, 524, 460, "Cloud_anim"),
            new Cloud(config->s_Cloud_ainm->s, gameLvL, 1000, 150, 524, 460, "Cloud_anim"),
            new Cloud(config->s_Cloud_ainm->s, gameLvL, 3000, 100, 524, 460, "Cloud_anim"),
            new Cloud(config->s_Cloud_ainm->s, gameLvL, 6000, 250, 524, 460, "Cloud_anim"),
            new Cloud(config->s_Cloud_ainm->s, gameLvL, 10000, 200, 524, 460, "Cloud_anim"),

            new Cloud(config->s_Cloud_small->s, gameLvL, 6800, 250, 524, 460, "Cloud_Small"),
            new Cloud(config->s_Cloud_small->s, gameLvL, 7500, 280, 524, 460, "Cloud_Small"),
            new Cloud(config->s_Cloud_small->s, gameLvL, 8000, 300, 524, 460, "Cloud_Small"),

            new Cloud(config->s_Cloud_middle->s, gameLvL, 12800, 260, 524, 460, "Cloud_Middle"),
            new Cloud(config->s_Cloud_middle->s, gameLvL, 11500, 234, 524, 460, "Cloud_Middle"),
            new Cloud(config->s_Cloud_middle->s, gameLvL, 2500, 380, 524, 460, "Cloud_Middle"),

            new Cloud(config->s_Cloud_middle->s, gameLvL, 7000, 380, 524, 460, "Cloud_Big"),
            new Cloud(config->s_Cloud_middle->s, gameLvL, 4500, 150, 524, 460, "Cloud_Big"),
            new Cloud(config->s_Cloud_middle->s, gameLvL, 10500, 435, 524, 460, "Cloud_Bog"),
    };
    cloudLvL[2] = {

    };
    cloudLvL[3] = {

    };
    cloudLvL[4] = {

    };
    cloudLvL[5] = {

    };
    cloudLvL[6] = {

    };
}