#include "gameOptions.h"

void GameOptions::PrintBanner() {
		fprintf(stderr, 
		"Ninja Engine (%s)\n"
		"binary1230(at)yahoo.com | http://einsteinsbreakfast.com\n"
		"(c) 2005 Dominic Cerquetti, this program is Free Software\n"
		"Licensed under the GNU GPL v2, see http://gnu.org\n\n",
		VERSION_STRING);
}

void GameOptions::PrintOptions(char* arg0) {
	if (!show_help) {
		fprintf(stderr, "type '%s -h' for more options..\n\n", arg0);
	} else {
		fprintf(stderr,
		"NOTE: .dat files MUST be in a dir in THIS folder called 'data'\n\n"

		"Usage: %s [options]\n"
		"-f            | try to force fullscreen mode\n"
		"-w            | try to force windowed mode\n"
		"-r file       | record a demo to 'file'\n"
		"-p file       | playback a demo from 'file'\n"
		"-h            | display this help message\n\n"
		, arg0);
	}
}

void GameOptions::Clear() {
	fullscreen = false;
	show_help = false;
	demo_record_filename = NULL;
	demo_playback_filename = NULL;

	is_valid = true;
}

bool GameOptions::ParseArguments(int argc, char* argv[]) {
	
	char c;
	bool _fullscreen_option_set = false;

	Clear();

	while ( (c = getopt(argc,argv,"r:p:fwh")) != -1) {
		switch (c) {

			case 'r':
				sscanf(optarg, "%u", &n);															
				break;

			case 'p':

				break;
			
			// display help
			case 'h':
				show_help = true;
				return (is_valid = false);
				break;
	
			// fullscreen or windowed
			case 'f': case 'w':
				if (_fullscreen_option_set) {
					fprintf(stderr,"Options ==> ERROR, Cannot select both fullscreen (-f) and windowed (-w) mode.\n");
					return (is_valid = false);
				} else if (c == 'f') {
					fullscreen = true;
					_fullscreen_option_set = true;
					fprintf(stderr, "Options ==> fullscreen mode enabled\n");
				} else if (c == 'w') {
					fullscreen = false;
					_fullscreen_option_set = true;
					fprintf(stderr, "Options ==> windowed mode enabled\n");
				}
				break;
	
			// : and ? mean something is weird
			default:
			case ':': case '?':
				fprintf(stderr, "Unrecognized command line option '-%c'\n", c);
				show_help = true;
				return (is_valid = false);
				break;
		}
	}
	return IsValid();
}

bool GameOptions::IsValid() {
	return is_valid;
}

bool GameOptions::IsFullscreen() {
	return fullscreen;
}
