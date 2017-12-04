# DynaBomber

- Created a UE4 C++ Project using the Top Down template (this avoids me having to recreate the wheel on some of the basic stuff, and
 gives me some base assets to work with)
- Removed point and click control and VR code
- Created new input method to limit movement to cardinal directions only
- Finished up movement and rotation code.
- Added second player and inputs for second player
- Set camera and map up
- Added basic zoom in/out based on player distance
- Created and added MapZones, these will be used to place blocks, bombs etc
- Random generation of which zones are blocks
- Switched MapZones from pure blueprint to code+blueprint
- Finished basic level setup in editor
- Added code to create and adjust a dynamic material to change the colour of each player (P1 = Red, P2 = Blue)
- Started adding gameplay code
- Added a bunch of code and BP script for bomb placement and explosion.
- Imported explosion asset from starter content.
- Destroy any boxes in explosion zone
- Added code + script for players in kill zone, and "respawn" (restart to random playerstart location)


I've spent around 6-8 hours over a few nights and one afternoon due to work and personal commitments. I've focused on just getting
the game basics in because of this, so I'm missing game flow (start/end screens, scoring/timing), pickups/bomb count (for these it was just 
going to add  some basic modifiers to bomb power and player movement speed in DynCharacter) and any UI. I did get some basic groundwork
done for those tasks but ran out of time to fully implement them. Hopefully this is enough to show that I can handle UE4 ;)

The majority of the work can be found in DynaBomberCharacter, DynaBomberPlayerController and DynaZone .h/cpp files and the CamreaBlueprint
and DynaZoneBP blueprints.

All art is taken from Epic's demo/starter content - modified as needed. The only code I had to look up was for two player controllers using
one input device, for which I used a guide on Epic's UE4 wiki (https://wiki.unrealengine.com/Local_Multiplayer_Tips#Multiple_Players_on_the_Keyboard_.28C.2B.2B.29)

Obviously with a bit more time I'd get those missing features in and then probably add more interesting pickups (maybe some sort of portal
system), have a tracking zooming camera based on the player location, gamepad support, AI and teamplay. I'd also like to re-do the map generation as I ended up doing most of the setup by hand. I did attempt some code to find neighbouring DynaZones using line trace, but it
was taking too long to implement so I moved on to other tasks.
