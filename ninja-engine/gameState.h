#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState;
class BaseInput;
class GameMode;
class AssetManager;
class GameSound;
class GameModes;
class ezSockets;
class GameNetwork;

//! Represents the current state of the game.

//! The MAIN class in the game - the centrally
//! coordinated object which initializes, runs, and destroys
//! the entire game.  Anything of importance starts in this
//! class somewhere.
class GameState {
	DECLARE_SINGLETON_CLASS(GameState)

	protected:
		ALLEGRO_TIMER* m_timer;

		bool should_redraw;

		//! Holds the current game's parsed XML data
		XMLNode xGame;
		
		//! Collection of all game modes (e.g. menu mode, simulation mode, etc)
		GameModes *modes;

		//! The game network functionality:
		GameNetwork *network;

		//! Fires off timer related events
		ALLEGRO_EVENT_QUEUE *event_queue = NULL;

		//! True if we are using the network
		bool IsUsingNetwork() {return network != NULL;};
		
		//! Initialize all game related stuff
		int InitSystems();								
		
		//! Init basic allegro stuff
		int InitAllegro();

		//! Init game timing
		bool InitAllegroEvents();
		
		//! Init input subsystems
		int InitInput();								

		//! Init sound system
		int InitSound();

		//! Init the game network
		int InitNetwork();
		
		//! Load master game config from an XML file, return an XMLNode which is
		//! the first game Mode's config we should now load.
		int LoadXMLConfig(std::string xml_filename);
		
		//! Load a game mode from an XML config file
		int LoadGameModes();

		//! Update the state of the game
		void Update();

		//! Draw the current state of the game
		void Draw();

		//! Update FPS display
		void UpdateFPS();
		
		//! Set to TRUE to immediately shutdown the game 
		bool exit_game;	
	
		//! Flag to enable DEBUG pause toggling
		bool paused;

		//! If a game has the same random seed, it will
		//! return the EXACT same sequence of random numbers.
		//! (useful for recording demos)
		int random_seed;
	
		//! Set to true if we are playing back a demo
		bool is_playing_back_demo;

		//! The current FPS rate
		int m_iCurrentFps;
					
	public:

		//! Shutdown the game
		void Shutdown();

		//! Initialize
		bool Init(const int argc, const char** argv);

		//! THE MAIN LOOP
		void RunMainLoop_BlockingHelper();

		void ProcessEvents();

		void TickIfNeeded();

		//! NOTE: Normally called by MainLoop()
		//! Sometimes GUI's and things will have to call this directly from ON_IDLE msgs
		void Tick();

		void SetPhysicsDebugDraw(bool value);

		void UpdateGlobalInput();

		//! Set the random seed value
 		void SetRandomSeed(int);

		inline bool IsPaused() {
			return paused;
		}

		inline void SetPaused(bool newState) {
			paused = newState;
		}
		
		//! Get the random seed value
		int GetRandomSeed() const;

		//! Returns true if we are playing back a demo
		bool IsPlayingBackDemo() {return is_playing_back_demo;};

		//! Unconditionally exit game
		void SignalGameExit();
		
		//! The current mode calls this to signal it wants to end
		void SignalEndCurrentMode();

		bool ShouldExit() { return exit_game; }
		
		~GameState();
};

#define GAMESTATE GameState::GetInstance()

#endif
