# Don’t Touch My Present

Hey, welcome to Don’t Touch My Present! This is my take on a quirky little game originally cooked up by the YouTuber Goodgis. Picture this: Santa’s got a gift, enemy hands are dropping from the sky, and it’s your job to dodge ‘em while racking up points. Simple, chaotic, and a total blast! I built this in C++ with SFML over a single caffeine-fueled weekend, and let me tell you—it was a ride. Now it’s here on GitHub for you to play, tweak, or just laugh at my wild journey.

------------ ![GIF](hands%20game%20menu.gif)     ------        ![GIF](hands%20game%20play.gif) ------------
## The Crazy Backstory
So, here’s the deal: I’m a guy who knew C++—like, “hello world” and some something pretty much. Game programming? SFML? whats that brother.... But I’d been binge-watching coding challenges on YouTube (you know, those “make a game in 48 hours” vibes), and Goodgis’s “Don’t Touch My Present” popped up. Bro made this game in PyGame (Python) & tbvh It looked fun to me. And I thought, “Why not? I’ve got a weekend, some coffee, and a stubborn reckless person who takes challenges as fun..." Anyways, i took challenge head-on, thinking how hard it can be... (pretty much hard enough that i wasted half of my day in setting up sfml in visual studio after watching countless tutorials & stuff on stackoverflow)

### Choosing Graphics/Game Library
I had watched couple of fun challenges on YouTube of PolyMars & Barji creating games in c++ so little did i know there're 3 libraries SDL, SFML & Raylib (thanks to goodgis i knew Raylib is C & not C++) so i'm left with SFML & SDL. Now which one to choose... well that was the easy part
As SFML stands for "Simple and Fast Multimedia Library" so... what else do i need when i'm getting something simple & fast 😭 (but who knew how simple and fast it's)

### Day 1: 
it was absolute chaos, well someone who knew how to print helloworld, loops, or maybe sort a linkedlist gotta know u have to install libraries to get goin... 
me's inner self: Ahhhh!!! les do it 5 min stuff
Setting Up Libraries alone took half of my motivation & half the day as well 😭, at the moment i was reconsidering why did i born into this accursed world... but yeah, i can't loose challenge, so buckled up again to get started
After taking hrs of youtube tutorials i managed to move a red circle on screen with help of keyboard, next thing was replacing dot with image of hand holding gift.... ez stuff i thought... that was the moment sprites textures stuff got introduced to me, after couple of hrs i managed to draw hands falling down (enemies) & player controlled with keyboard & called it a day

### Day 2: 
well code is looking mess rn and I've to redo all work for each image i put... so i used my dev experience in java... and created multiple classes... making shit easier for me to manage... now create an object and other hand is there, ez scenes... then i created main menu it was pretty much copy/paste (like jus adjusting positions) <br>
✅ Main Menu Done <br>
✅ Enemy's Falling Done <br>
✅ Player Movement Done <br>
 but game doesn't feel alive... cuz there's no collision and also hands felt fun in original game by goodgis... so i put sin wave for floating animation... that's pretty much mathematics figured in less than hrs and thanks too OOP it was pretty much easy to replicate it on everything required...
Now it looks cool but still we're missing collisions... but its also 1 o clock, so les call it a day

### Day 3:

Added Collisions, scoreboard, sound effects (cheers! chops! chaos!), and a high score system—because who doesn’t love bragging rights? I barely slept, lived on snacks, and debugged like my life depended on it. By Sunday night, I had a game. A real, playable game! Was it perfect? Nope. Was it mine? Heck yes (almost cuz assets were by goodgis) but yeah i somehow managed to complete challenge in 3 days <i barely finished it b4 12 o clock night>
was it worth it? yeah alot...
was it fun? it was breath-yaking fun 😭

This wasn’t just a weekend project—it was a head-on, “I’m gonna figure this out or bust” challenge. Three days, zero game dev experience, and a whole lot of grit later, here we are. Hope you enjoy it as much as I loved (and sometimes hated) making it!


## Lets Get it working for You

### Prerequisites

You’ll need a few things to run this:
- **SFML**: I used version 2.6.2. Grab it from [sfml-dev.org](https://www.sfml-dev.org/).
- **C++ Compiler**: well me went with Visual Studio 2022

Just Want to Play it? download this.... [Don't Touch My Present - SFML/C++](https://drive.google.com/file/d/18l7sG139CC4g9HB6QAbVFnbP7Ynu_k2J/view?usp=sharing)

### Installation

1. **Clone the Repo**:
   ```bash
   git clone https://github.com/Sally4D/dont-touch-my-present.git
   cd dont-touch-my-present
### SFML Setup:
-  Add SFML include/lib paths, link the libs, and hit build. Pray it works first try (it won’t).
-  Use YT for tutorials

## How to Play
### Controls:
-  **WASD:** Move Santa’s hand and gift.
-  **Escape:** Back to the menu (or just close the window).
-  **Goal:** Dodge enemy hands, hit their lines to score, and avoid that slap sound.
-  **Tip:** Enemies get speedy—keep your eyes peeled!

## Project Breakdown
-  Component.h/cpp: Images and text with bouncy animations.
-  EnemyHand.h/cpp: The pesky hands dropping down.
-  Player.h/cpp: Santa and his gift, under your command.
-  Game.h/cpp: The heart of the action—game loop and logic.
-  MainMenu.h/cpp: A chill start screen to set the mood.
-  ResourceManager.h/cpp: My proud moment—efficient resource loading.
-  main.cpp: Kicks things off with some background tunes.
-  data/: All the assets—don’t lose this!

## Shoutouts
Goodgis: The OG creator who inspired this madness—check out his vid!
SFML Crew: For a library that’s equal parts awesome and “why won’t you work?!”
Me: For not giving up when Visual Studio laughed in my face.
Wanna Tinker?
Fork it, break it, make it better—I’m all for it! Add levels, fix my janky collision, or crank up the chaos with more sounds. Pull requests are cool—just keep the fun alive.

## Quirks I Noticed
-  Sound effects might overlap weirdly (single sf::Sound life).
-  Missing assets? Console will scream—double-check data/.
-  Window’s 360x640—might look funky on giant monitors.

Thanks for checking out my 3-day coding sprint! Hope you get a kick out of dodging those hands. Happy gaming, and maybe I’ll see you in the next challenge! 🎁
