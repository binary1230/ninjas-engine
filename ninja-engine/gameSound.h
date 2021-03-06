#ifndef GAMESOUND_H
#define GAMESOUND_H

class SoundDef;

//! Maps a sound name to it's handle (e.g. "jump" to the sample)
typedef map<std::string, SoundDef*> SoundMapping;

class GameSound {

		DECLARE_SINGLETON_CLASS(GameSound)
				
		protected:
			//! If false, then this class doesn't output any sound
			bool sound_enabled;

			//! Holds pointers to SAMPLE's.  Do NOT create or free these
			//! pointers, AssetManager does that.
			SoundMapping soundMap;

			//! Pitch altering params
			bool use_variable_pitch;
			int freq_range;

			std::string current_music;
			ALLEGRO_SAMPLE_ID current_music_id;

			ALLEGRO_SAMPLE* FindCachedSoundByName(const char* name);

			bool IsThisMusicPlayingAlready(std::string name);

		public:
			//! Load and cache a sound
			//! example: LoadSound("sounds/jump.wav", "jump")
			//! Then you can PlaySound("jump") to hear it.
			ALLEGRO_SAMPLE* LoadSound(const char* filename, const char* sound_name, bool load_resident = false);
	
			//! Load all sounds from a <sounds> block in XML
			bool LoadSounds(XMLNode &xSounds, bool load_resident = false);
			
			//! Load a piece of music
			bool PlayMusic(const char* filename);
			void StopMusic();			
			
			void PlaySound(	std::string name, unsigned int pan = 128, 
							ALLEGRO_PLAYMODE loop = ALLEGRO_PLAYMODE_ONCE, ALLEGRO_SAMPLE_ID* sound_id_out = NULL);

			void StopSound(ALLEGRO_SAMPLE_ID* sample_id);

			bool Init(bool _sound_enabled);

			void Update();

			//! Shutdown the sound system
			void Shutdown();

			void ClearSoundMap(bool keep_resident_sounds = true);

			~GameSound();
};

#define SOUND GameSound::GetInstance()

#endif // GAMESOUND_H
