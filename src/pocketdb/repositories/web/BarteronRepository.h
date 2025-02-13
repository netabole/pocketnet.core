// Copyright (c) 2018-2022 The Pocketnet developers
// Distributed under the Apache 2.0 software license, see the accompanying
// https://www.apache.org/licenses/LICENSE-2.0

#ifndef SRC_RPC_BARTERON_REPOSITORY_H
#define SRC_RPC_BARTERON_REPOSITORY_H

#include "pocketdb/repositories/BaseRepository.h"
#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptor/transformed.hpp>

namespace PocketDb
{
    using namespace std;
    using boost::algorithm::join;
    using boost::adaptors::transformed;

    struct BarteronOffersFeedDto
    {
        Pagination Page;
        string Language = "";
        vector<int> Tags;
        string Location = "";
        int64_t PriceMax = 0;
        int64_t PriceMin = 0;
        string Search = "";
    };

    struct BarteronOffersDealDto
    {
        Pagination Page;
        string Offer = "";
        string Address = "";
        int Location = -1;
        int Price = -1;
    };

    class BarteronRepository : public BaseRepository
    {
    public:
        explicit BarteronRepository(SQLiteDatabase& db) : BaseRepository(db) {}

        vector<string> GetAccountIds(const vector<string>& addresses);
        vector<string> GetAccountOffersIds(const string& address);
        vector<string> GetFeed(const BarteronOffersFeedDto& args);
        vector<string> GetDeals(const BarteronOffersDealDto& args);

    };

    typedef std::shared_ptr<BarteronRepository> BarteronRepositoryRef;
}

#endif //SRC_RPC_BARTERON_REPOSITORY_H
