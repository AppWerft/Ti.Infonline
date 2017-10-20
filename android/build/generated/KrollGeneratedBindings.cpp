/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "ti.infonline.InfonlineModule.h"


namespace titanium {
namespace bindings {
#line 15 "/Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf"
struct BindEntry;
/* maximum key range = 1, duplicates = 0 */

class InfonlineBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
InfonlineBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct BindEntry *
InfonlineBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 1,
      MIN_WORD_LENGTH = 28,
      MAX_WORD_LENGTH = 28,
      MIN_HASH_VALUE = 28,
      MAX_HASH_VALUE = 28
    };

  static struct BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 17 "/Users/fuerst/Documents/MLearning/Ti.Infoline/android/build/generated/KrollGeneratedBindings.gperf"
      {"ti.infonline.InfonlineModule",::ti::infonline::InfonlineModule::bindProxy,::ti::infonline::InfonlineModule::dispose}
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
