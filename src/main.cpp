#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>

using namespace std;

namespace Util{
    /** @brief The array of the strings. */
    using StrVec = std::vector<std::string>;

    /**
     * @brief Separate the strings.
     * @param text The string you want to separate.
     * @param delim The delim string. ( def: " " )
     * @return The object of the std::Vector for std::string, which was separated.
    */
    StrVec split( const std::string& text, const std::string& delim = std::string(" ") ){
        StrVec res;
        int end = 0, begin = 0, n = 0;
        while( true ){
            end   = text.find( delim, begin );
            if( end == std::string::npos ){
                res.push_back( text.substr( begin, (text.size() - begin) ) );
                break;
            }
            n = (end - begin);
            res.push_back( text.substr( begin, n ) );
            begin = end + 1;
        }
    return res;
    }

    /**
     * @brief Convert the data to the string.
     * @param val The data you want to convert.
     * @return The string which was converted from the data.
     */
    template<typename T> std::string ToString( T val ){
        std::stringstream ss;
        ss << val << flush;
    return ss.str();
    }
}

namespace Original{
    namespace Hand_Types{
        enum Hand_Type{
            Rock,
            Paper,
            Scissors,
            Unknown
        };
    }

    namespace Results{
        enum Result{
            Lose,
            Draw,
            Win,
            Unknown
        };
    }
    class Hand{
        public:
            Hand( char hand ) : hand_(CalcType(hand)){}
            ~Hand() = default;

            Results::Result Won( const Hand& hand ){
                if( this->hand_ == Hand_Types::Rock && hand.hand_ == Hand_Types::Rock ) return Results::Draw;
                if( this->hand_ == Hand_Types::Paper && hand.hand_ == Hand_Types::Paper ) return Results::Draw;
                if( this->hand_ == Hand_Types::Scissors && hand.hand_ == Hand_Types::Scissors ) return Results::Draw;

                if( this->hand_ == Hand_Types::Rock && hand.hand_ == Hand_Types::Scissors ) return Results::Win;
                if( this->hand_ == Hand_Types::Paper && hand.hand_ == Hand_Types::Rock ) return Results::Win;
                if( this->hand_ == Hand_Types::Scissors && hand.hand_ == Hand_Types::Paper ) return Results::Win;

                if( this->hand_ == Hand_Types::Scissors && hand.hand_ == Hand_Types::Rock ) return Results::Lose;
                if( this->hand_ == Hand_Types::Rock && hand.hand_ == Hand_Types::Paper ) return Results::Lose;
                if( this->hand_ == Hand_Types::Paper && hand.hand_ == Hand_Types::Scissors ) return Results::Lose;
            return Results::Unknown;
            }
        protected:
            Hand_Types::Hand_Type CalcType( char hand ){
                if( hand == 'R' ) return Hand_Types::Rock;
                if( hand == 'P' ) return Hand_Types::Paper;
                if( hand == 'S' ) return Hand_Types::Scissors;
            return Hand_Types::Unknown;
            }
        private:
            Hand_Types::Hand_Type hand_;
    };

    class RockPaperScissors{
        public:
            RockPaperScissors( const Hand& user, const Hand& computer ) : user_(user),computer_(computer){}
            ~RockPaperScissors() = default;

            Results::Result CalcResult( void ){
                return user_.Won( computer_ );
            }
        private:
            Hand user_;
            Hand computer_;
    };

    class Counter{
        public:
            Counter() : win_(0),lose_(0),draw_(0){}
            ~Counter() = default;

            void Count( Results::Result res ){
                if( res == Results::Win ){ win_++; return; }
                if( res == Results::Lose ){ lose_++; return; }
                if( res == Results::Draw ){ draw_++; return; }
            }

            void Print( void ){
                cout << "Win : " << win_ << endl;
                cout << "Lose: " << lose_ << endl;
                cout << "Draw: " << draw_ << endl;
            }
        private:
            int win_;
            int lose_;
            int draw_;
    };
}


int main( int argc, char** argv ){
    int n;
    cin >> n;

    Original::Counter counter;
    for( int i = 0; i < n; i++ ){
        char user_hand, computer_hand;
        cin >> user_hand >> computer_hand;
        std::unique_ptr<Original::RockPaperScissors> rps(new Original::RockPaperScissors(
            Original::Hand(user_hand), Original::Hand(computer_hand)
        ));
        counter.Count( rps->CalcResult() );
    }

    counter.Print();
return 0;
}
