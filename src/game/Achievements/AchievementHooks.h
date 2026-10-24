/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_ACHIEVEMENT_HOOKS_H
#define MANGOS_ACHIEVEMENT_HOOKS_H

#include "Platform/Define.h"

#include <string>

class BattleGround;
class BattleGroundWS;
class ChatHandler;
class GameObject;
class Group;
class Item;
class Loot;
class MailDraft;
class MovementInfo;
class ObjectGuid;
class Player;
class Quest;
class Spell;
class TradeData;
class Unit;
class WorldPacket;
namespace Taxi { class Tracker; }

struct AuctionEntry;
struct FactionEntry;
struct LootItem;
struct Mail;

/**
 * Game events the achievements module (BUILD_ACHIEVEMENTS) listens to.
 *
 * The core calls these through sAchievementHooks. Without a registered
 * implementation every hook is a no-op, so the core never depends on the module.
 * Hooks returning bool may handle the event: true makes the core skip its own handling.
 */
class AchievementHooks
{
    public:
        virtual ~AchievementHooks() = default;

        static AchievementHooks& Instance();
        // The module registers its single implementation at startup.
        static void Register(AchievementHooks* hooks);

        // World lifecycle
        virtual void OnLoadConfig() {}                              // before the world is loaded
        virtual void OnWorldInitialized() {}
        virtual void OnWorldUpdated(uint32 /*elapsed*/) {}
        virtual bool OnChatCommand(ChatHandler* /*handler*/, const std::string& /*command*/) { return false; }

        // Player lifecycle
        virtual void OnPreCharacterCreated(Player* /*player*/) {}
        virtual void OnPreLoadFromDB(Player* /*player*/) {}
        virtual void OnLoadFromDB(Player* /*player*/) {}
        virtual void OnSaveToDB(Player* /*player*/) {}
        virtual void OnDeleteFromDB(uint32 /*playerId*/) {}
        virtual void OnLogOut(Player* /*player*/) {}

        // Player events
        virtual bool OnUseItem(Player* /*player*/, Item* /*item*/) { return false; }
        virtual void OnMoveItemToInventory(Player* /*player*/, Item* /*item*/) {}
        virtual void OnStoreItem(Player* /*player*/, Item* /*item*/) {}
        virtual void OnEquipItem(Player* /*player*/, Item* /*item*/) {}
        virtual void OnSellItem(Player* /*player*/, Item* /*item*/, uint32 /*money*/) {}
        virtual void OnResetTalents(Player* /*player*/, uint32 /*cost*/) {}
        virtual void OnHandleFall(Player* /*player*/, const MovementInfo& /*movementInfo*/, float /*lastFallZ*/, uint32 /*damage*/) {}
        virtual void OnDeath(Player* /*player*/, Unit* /*killer*/) {}
        virtual void OnDeath(Player* /*player*/, uint8 /*environmentalDamageType*/) {}
        virtual void OnGiveLevel(Player* /*player*/, uint32 /*level*/) {}
        virtual void OnModifyMoney(Player* /*player*/, int32 /*diff*/) {}
        virtual void OnSetReputation(Player* /*player*/, const FactionEntry* /*factionEntry*/, int32 /*standing*/, bool /*incremental*/) {}
        virtual void OnUpdateSkill(Player* /*player*/, uint16 /*skillId*/) {}
        virtual void OnRewardHonor(Player* /*player*/, Unit* /*victim*/) {}
        virtual void OnUpdateHonor(Player* /*player*/) {}
        virtual void OnDuelComplete(Player* /*player*/, Player* /*opponent*/, uint8 /*duelCompleteType*/) {}
        virtual void OnKilledMonsterCredit(Player* /*player*/, uint32 /*entry*/, ObjectGuid& /*guid*/) {}
        virtual void OnRewardPlayerAtKill(Player* /*player*/, Unit* /*victim*/) {}
        virtual bool OnHandlePageTextQuery(Player* /*player*/, const WorldPacket& /*packet*/) { return false; }
        virtual void OnRewardQuest(Player* /*player*/, const Quest* /*quest*/) {}
        virtual void OnAbandonQuest(Player* /*player*/, uint32 /*questId*/) {}
        virtual void OnTaxiFlightRouteStart(Player* /*player*/, const Taxi::Tracker& /*taxiTracker*/, bool /*initial*/) {}
        virtual void OnTaxiFlightRouteEnd(Player* /*player*/, const Taxi::Tracker& /*taxiTracker*/, bool /*final*/) {}
        virtual void OnAddSpell(Player* /*player*/, uint32 /*spellId*/) {}
        virtual void OnEmote(Player* /*player*/, Unit* /*target*/, uint32 /*emote*/) {}
        virtual void OnBuyBankSlot(Player* /*player*/, uint32 /*slot*/, uint32 /*price*/) {}
        virtual void OnSummoned(Player* /*player*/, const ObjectGuid& /*summoner*/) {}
        virtual void OnAreaExplored(Player* /*player*/, uint32 /*areaId*/) {}
        virtual void OnTradeAccepted(Player* /*player*/, Player* /*trader*/, TradeData* /*playerTrade*/, TradeData* /*traderTrade*/) {}

        // Game objects
        virtual bool OnUse(GameObject* /*gameObject*/, Unit* /*user*/) { return false; }

        // Units
        virtual void OnDealDamage(Unit* /*unit*/, Unit* /*victim*/, uint32 /*health*/, uint32 /*damage*/) {}
        virtual void OnKill(Unit* /*unit*/, Unit* /*victim*/) {}
        virtual void OnDealHeal(Unit* /*unit*/, Unit* /*victim*/, int32 /*gain*/, uint32 /*addHealth*/) {}

        // Spells
        virtual void OnHit(Spell* /*spell*/, Unit* /*caster*/, Unit* /*victim*/) {}
        virtual void OnCast(Spell* /*spell*/, Unit* /*caster*/, Unit* /*victim*/) {}

        // Loot
        virtual void OnSendGold(Loot* /*loot*/, Player* /*player*/, uint32 /*gold*/, uint8 /*lootMethod*/) {}
        virtual void OnHandleLootMasterGive(Loot* /*loot*/, Player* /*target*/, LootItem* /*lootItem*/) {}
        virtual void OnPlayerRoll(Loot* /*loot*/, Player* /*player*/, uint32 /*itemSlot*/, uint8 /*rollType*/) {}
        virtual void OnPlayerWinRoll(Loot* /*loot*/, Player* /*player*/, uint8 /*rollType*/, uint8 /*rollAmount*/, uint32 /*itemSlot*/, uint8 /*inventoryResult*/) {}

        // Battlegrounds
        virtual void OnStartBattleGround(BattleGround* /*battleground*/) {}
        virtual void OnEndBattleGround(BattleGround* /*battleground*/, uint32 /*winnerTeam*/) {}
        virtual void OnUpdatePlayerScore(BattleGround* /*battleground*/, Player* /*player*/, uint8 /*scoreType*/, uint32 /*value*/) {}
        virtual void OnLeaveBattleGround(BattleGround* /*battleground*/, Player* /*player*/) {}
        virtual void OnJoinBattleGround(BattleGround* /*battleground*/, Player* /*player*/) {}
        virtual void OnPickUpFlag(BattleGroundWS* /*battleground*/, Player* /*player*/, uint32 /*team*/) {}

        // Groups
        virtual void OnAddMember(Group* /*group*/, Player* /*player*/, uint8 /*method*/) {}

        // Auction house
        virtual void OnSellItem(AuctionEntry* /*auctionEntry*/, Player* /*player*/) {}
        virtual void OnUpdateBid(AuctionEntry* /*auctionEntry*/, Player* /*player*/, uint32 /*newBid*/) {}
        virtual void OnAuctionBidWinning(AuctionEntry* /*auctionEntry*/, const ObjectGuid& /*owner*/, const ObjectGuid& /*bidder*/) {}

        // Mail
        virtual void OnSendMail(const MailDraft& /*mail*/, Player* /*player*/, const ObjectGuid& /*receiver*/, uint32 /*cost*/) {}
        virtual void OnMailTakeItem(Mail* /*mail*/, Player* /*player*/, Item* /*item*/, const ObjectGuid& /*sender*/) {}
};

#define sAchievementHooks AchievementHooks::Instance()

#ifdef BUILD_ACHIEVEMENTS
// Implemented by the achievements module: creates and registers its hooks. Called
// explicitly (not from a static initializer) so the linker keeps the module.
void AddAchievementHooks();
#endif

#endif
