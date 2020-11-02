#include <belr/grammarbuilder.h>
#include <belr/abnf.h>

using namespace std;

namespace bellesip {
    namespace Parser {
        class SDP {
            public:
                static SDP *getInstance();
                void * parse(const string &input, const string &rule);
            private:
                static SDP *instance;
                SDP();
                ~SDP();
                shared_ptr<belr::Grammar> loadGrammar();
                shared_ptr<belr::Parser<void*>> _parser;
        };
    }
}
