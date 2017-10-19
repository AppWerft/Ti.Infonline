/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "ti.infoline.InfolineModule.h"


namespace titanium {
namespace bindings {
#line 15 "/Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf"
struct BindEntry;
/* maximum key range = 1, duplicates = 0 */

class InfolineBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
InfolineBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct BindEntry *
InfolineBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 1,
      MIN_WORD_LENGTH = 26,
      MAX_WORD_LENGTH = 26,
      MIN_HASH_VALUE = 26,
      MAX_HASH_VALUE = 26
    };

  static struct BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 17 "/Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf"
      {"ti.infoline.InfolineModule",::ti::infoline::InfolineModule::bindProxy,::ti::infoline::InfolineModule::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 18 "/Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf"

}
}
