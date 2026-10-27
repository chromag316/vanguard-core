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

// Vanguard: scripts for Vanguard's own spells (vanguard-db world/0011_calling_companion.sql).

#include "Spells/Scripts/SpellScript.h"
#include "Spells/Spell.h"
#include "Entities/Player.h"

#ifdef ENABLE_PLAYERBOTS
#include "playerbot/PlayerbotMgr.h"
#endif

// 90001 - Summoning: a copy of Hearthstone (10-second cast) that a player casts to
// summon a companion. When it completes, the companion it was cast for comes (playerbots).
struct CallingCompanion : public SpellScript
{
    void OnSuccessfulFinish(Spell* spell) const override
    {
#ifdef ENABLE_PLAYERBOTS
        if (Player* player = dynamic_cast<Player*>(spell->GetCaster()))
            if (PlayerbotMgr* mgr = player->GetPlayerbotMgr())
                mgr->FinishCompanionSummon();
#endif
    }
};

void LoadVanguardScripts()
{
    RegisterSpellScript<CallingCompanion>("spell_vanguard_calling_companion");
}
