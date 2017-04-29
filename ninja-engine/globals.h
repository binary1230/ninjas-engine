/* Global vars/defines */

#ifndef GLOBALS_H
#define GLOBALS_H

typedef unsigned int uint;

// Not a great rand... only uses lower bits, not good.
#define Rand(lower, upper) \
((rand() % (int(upper) - int(lower) + 1)) + int(lower))

#define DEFAULT_SCREEN_SIZE_X	1024
#define DEFAULT_SCREEN_SIZE_Y	650

// PACKAGE and VERSION come from autotools (config.h)
#ifdef HAVE_CONFIG_H
#define VERSION_STRING PACKAGE"-"VERSION
#else
#define VERSION_STRING "ninjas-engine"
#endif // HAVE_CONFIG_H

// the fps (not ever changed)
// timestep is 1/FPS
#define FPS 60
// #define FPS 30
#define TIMESTEP 1/FPS

#define ONEEIGHTY_OVER_PI 57.2957795
#define PI_OVER_ONEEIGHTY 0.0174532925

#define DEG_TO_RAD(x) PI_OVER_ONEEIGHTY * x
#define RAD_TO_DEG(x) ONEEIGHTY_OVER_PI * x

//! A fudge value.  You can't compare two floats
//! directly, we just want to know if they are close.
//! This defines how close they must be to be considered
//! 'equal'
#define TOLERANCE 0.00001

//! The default debug message level.  0 = none, 1 = all
//! This value is overridden by the '-m' command line switch
#define DEFAULT_DEBUG_MSG_LEVEL 0

// (65536) size of audiostream buffer for music
#define DEFAULT_MUSIC_BUFFER_SIZE   (1<<16) 

// (32768) amount of data to read from disk each time 
#define DEFAULT_MUSIC_DATA_SIZE  (1<<15) 

#define SAFE_DELETE(x) \
				if (x) delete x; x = NULL

// Misc: Take a string and split it based on a delimiter, put the
// resulting strings into a list.
// 
// For example: StringSplit("Hey|what's|up","|", out_list) will
// put 3 things, "Hey", "what's", and "Up", into out_list.
void StringSplit(std::string str, std::string delim, std::vector<std::string> &results);

void DebugTrace( const char * format, ... );

#ifdef TRACE
#undef TRACE
#endif 

//#ifdef _DEBUG
#define TRACE DebugTrace
//#else
//#define TRACE
//#endif // _DEBUG


namespace boost {
	namespace serialization {

		// custom serializable types for Boost

		template<class Archive>
		void serialize(Archive & ar, ALLEGRO_COLOR& c, const unsigned int version)
		{
			ar & boost::serialization::make_nvp("r", c.r);
			ar & boost::serialization::make_nvp("g", c.g);
			ar & boost::serialization::make_nvp("b", c.b);
			ar & boost::serialization::make_nvp("a", c.a);
		}

		template<class Archive>
		void serialize(Archive & ar, b2Vec2& v, const unsigned int version)
		{
			ar & boost::serialization::make_nvp("x", v.x);
			ar & boost::serialization::make_nvp("y", v.y);
		}


	} // namespace serialization
} // namespace boost

#define CREATE_PROPERTY(type, var)									\
	protected:														\
		type _##var;												\
	public:															\
		inline type GetProp##var() { return _##var; }				\
		inline void SetProp##var(type val)	{ _##var = val;	}
		

// #define REDIRECT_STDERR 1
#define REDIRECT_STDERR_FILENAME "/Users/dcerquetti/game.log"

#endif // GLOBALS_H
