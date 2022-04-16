/* Hearst patterns to implement
 * 
 self.__adj_stopwords = [
            'able', 'available', 'brief', 'certain',
            'different', 'due', 'enough', 'especially', 'few', 'fifth',
            'former', 'his', 'howbeit', 'immediate', 'important', 'inc',
            'its', 'last', 'latter', 'least', 'less', 'likely', 'little',
            'many', 'ml', 'more', 'most', 'much', 'my', 'necessary',
            'new', 'next', 'non', 'old', 'other', 'our', 'ours', 'own',
            'particular', 'past', 'possible', 'present', 'proud', 'recent',
            'same', 'several', 'significant', 'similar', 'such', 'sup', 'sure'
        ]


        # format is <hearst-pattern>, <general-term>
        # so, what this means is that if you apply the first pattern,
        # the first Noun Phrase (NP)
        # is the general one, and the rest are specific NPs
            
        '(NP_\\w+ (, )?such as (NP_\\w+ ?(, )?(and |or )?)+)',
        '(such NP_\\w+ (, )?as (NP_\\w+ ?(, )?(and |or )?)+)',
        '((NP_\\w+ ?(, )?)+(and |or )?other NP_\\w+)',
        '(NP_\\w+ (, )?include (NP_\\w+ ?(, )?(and |or )?)+)',
        '(NP_\\w+ (, )?especially (NP_\\w+ ?(, )?(and |or )?)+)',

         '((NP_\\w+ ?(, )?)+(and |or )?any other NP_\\w+)',
         '((NP_\\w+ ?(, )?)+(and |or )?some other NP_\\w+)',
         '((NP_\\w+ ?(, )?)+(and |or )?be a NP_\\w+)',
         '(NP_\\w+ (, )?like (NP_\\w+ ? (, )?(and |or )?)+)',
         'such (NP_\\w+ (, )?as (NP_\\w+ ? (, )?(and |or )?)+)',
         '((NP_\\w+ ?(, )?)+(and |or )?like other NP_\\w+)',
         '((NP_\\w+ ?(, )?)+(and |or )?one of the NP_\\w+)',
         '((NP_\\w+ ?(, )?)+(and |or )?one of these NP_\\w+)',
         '((NP_\\w+ ?(, )?)+(and |or )?one of those NP_\\w+)',
         'example of (NP_\\w+ (, )?be (NP_\\w+ ? '
         '(, )?(and |or )?)+)',
         '((NP_\\w+ ?(, )?)+(and |or )?be example of NP_\\w+)',
         '(NP_\\w+ (, )?for example (, )?'
         '(NP_\\w+ ?(, )?(and |or )?)+)',
         '((NP_\\w+ ?(, )?)+(and |or )?which be call NP_\\w+)',
         '((NP_\\w+ ?(, )?)+(and |or )?which be name NP_\\w+)',
         '(NP_\\w+ (, )?mainly (NP_\\w+ ? (, )?(and |or )?)+)',
         '(NP_\\w+ (, )?mostly (NP_\\w+ ? (, )?(and |or )?)+)',
         '(NP_\\w+ (, )?notably (NP_\\w+ ? (, )?(and |or )?)+)',
         
         '(NP_\\w+ (, )?particularly (NP_\\w+ ? '
         '(, )?(and |or )?)+)',
         
         '(NP_\\w+ (, )?principally (NP_\\w+ ? (, )?(and |or )?)+)',
         
         '(NP_\\w+ (, )?in particular (NP_\\w+ ? '
         '(, )?(and |or )?)+)',
        '(NP_\\w+ (, )?except (NP_\\w+ ? (, )?(and |or )?)+)',
        '(NP_\\w+ (, )?other than (NP_\\w+ ? (, )?(and |or )?)+)',
        '(NP_\\w+ (, )?e.g. (, )?(NP_\\w+ ? (, )?(and |or )?)+)',
        '(NP_\\w+ \\( (e.g.|i.e.) (, )?(NP_\\w+ ? (, )?(and |or )?)+'
        '(\\. )?\\))',
        '(NP_\\w+ (, )?i.e. (, )?(NP_\\w+ ? (, )?(and |or )?)+)',
        '((NP_\\w+ ?(, )?)+(and|or)? a kind of NP_\\w+)',
        '((NP_\\w+ ?(, )?)+(and|or)? kind of NP_\\w+)',
        '((NP_\\w+ ?(, )?)+(and|or)? form of NP_\\w+)',
        '((NP_\\w+ ?(, )?)+(and |or )?which look like NP_\\w+)',
        '((NP_\\w+ ?(, )?)+(and |or )?which sound like NP_\\w+)',
        
        '(NP_\\w+ (, )?which be similar to (NP_\\w+ ? '
        '(, )?(and |or )?)+)',
        
        '(NP_\\w+ (, )?example of this be (NP_\\w+ ? '
        '(, )?(and |or )?)+)',
        
        '(NP_\\w+ (, )?type (NP_\\w+ ? (, )?(and |or )?)+)',
        '((NP_\\w+ ?(, )?)+(and |or )? NP_\\w+ type)',
        '(NP_\\w+ (, )?whether (NP_\\w+ ? (, )?(and |or )?)+)',
        '(compare (NP_\\w+ ?(, )?)+(and |or )?with NP_\\w+)',
        '(NP_\\w+ (, )?compare to (NP_\\w+ ? (, )?(and |or )?)+)',
        
        '(NP_\\w+ (, )?among -PRON- (NP_\\w+ ? '
        '(, )?(and |or )?)+)',
       
        '((NP_\\w+ ?(, )?)+(and |or )?as NP_\\w+)',
        
        '(NP_\\w+ (, )? (NP_\\w+ ? (, )?(and |or )?)+ '
        'for instance)',
        
        '((NP_\\w+ ?(, )?)+(and|or)? sort of NP_\\w+)',
       
        '(NP_\\w+ (, )?which may include (NP_\\w+ '
        '?(, )?(and |or )?)+)',
*/


#include "math.hpp"
#include <fmt/core.h>

namespace syntactic_segmentation {
  
  void print_strings (const std::vector<std::string> & vect_of_str) {
    for (auto x : vect_of_str) fmt::print("{} ",x);
    fmt::print("\n");
  }
}
