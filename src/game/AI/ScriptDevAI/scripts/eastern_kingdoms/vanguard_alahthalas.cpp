/* This file is part of the ScriptDev2 Project. See AUTHORS file for Copyright information
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

/* ScriptData
SDName: Vanguard_Alahthalas
SD%Complete: 100
SDComment: Vanguard: Alah'Thalas and the Thalassian Highlands (High Elf zones, ported from Turtle WoW)
SDCategory: Alah'Thalas
EndScriptData

*/

#include "AI/ScriptDevAI/include/sc_common.h"

/*######
## go_translocation_orb
## Two orbs in Alah'Thalas link the portal platform (where portals to the city arrive) with
## the ground below; using one moves the player to the other.
######*/

enum
{
    GO_TRANSLOCATION_ORB_UP     = 3000224,  // on the platform; takes you down
    GO_TRANSLOCATION_ORB_DOWN   = 3000225,  // on the ground; takes you up
};

bool GOUse_go_translocation_orb(Player* player, GameObject* go)
{
    switch (go->GetEntry())
    {
        case GO_TRANSLOCATION_ORB_UP:   player->TeleportTo(0, 4235.40f, -2778.20f, 20.65f, 6.25f); break;
        case GO_TRANSLOCATION_ORB_DOWN: player->TeleportTo(0, 4225.31f, -2723.46f, 121.87f, 0.70f); break;
        default: return false;
    }
    return true;
}

void AddSC_vanguard_alahthalas()
{
    Script* pNewScript = new Script;
    pNewScript->Name = "go_translocation_orb";
    pNewScript->pGOUse = &GOUse_go_translocation_orb;
    pNewScript->RegisterSelf();
}
