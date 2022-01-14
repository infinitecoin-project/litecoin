// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "consensus/merkle.h"

#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

#include "chainparamsseeds.h"

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "Miami Heat rout Indiana Pacers 99-76, advance to NBA Finals on June 3, 2013";
    const CScript genesisOutputScript = CScript() << ParseHex("040184710fa689ad5023690c80f3a49c8f13f8d45b8c857fbcbc8bc4a8e4d3eb4b10f4d4604fa08dce601aaf0f470216fe1b51850b4acf21b179c45070ac7b03a9") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 86400;
        consensus.nMajorityEnforceBlockUpgrade = 30240;    // 75%
        consensus.nMajorityRejectBlockOutdated = 38304;    // 95%
        consensus.nMajorityWindow = 40320;    //Infinitecoin  2880*14day  
        //consensus.BIP34Height = 227931;
        //consensus.BIP34Hash = uint256S("0x000000000000024b89b42a942fe0d9fea3bb44ab7bd1b19115dd6a759c0808b8");
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 60 * 60;
        consensus.nPowTargetSpacing = 30;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xfb;
        pchMessageStart[1] = 0xc0;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("040184710fa689ad5023690c80f3a49c8f13f8d45b8c857fbcbc8bc4a8e4d3eb4b10f4d4604fa08dce601aaf0f470216fe1b51850b4acf21b179c45070ac7b03a9");
        nDefaultPort = 9321;
        nMaxTipAge = 24 * 60 * 60;
        nPruneAfterHeight = 100000;

        genesis = CreateGenesisBlock(1370324666, 113458625, 0x1e0ffff0, 1, 524288 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0xb10d5e83a5b2e62d9d872096bc20cae1a276ae6aacc02a71a5832b1fc9aeff85"));
        assert(genesis.hashMerkleRoot == uint256S("0x87605f6741961e869237b3d78fb271cdca70c67f1bb876992fda97ccd9036220"));

        vSeeds.push_back(CDNSSeedData("infinitecoin.com", "dnsseed.infinitecoin.com"));
        vSeeds.push_back(CDNSSeedData("ifcf2pool.com", "dnsseed.ifcf2pool.com"));
	vSeeds.push_back(CDNSSeedData("ifcp2pool.com", "dnsseed.ifcp2pool.com"));
        vSeeds.push_back(CDNSSeedData("amxpool.com", "dnsseed.amxpool.com"));
        vSeeds.push_back(CDNSSeedData("amzpool.com", "dnsseed.amzpool.com"));
        vSeeds.push_back(CDNSSeedData("bmapool.com", "dnsseed.bmapool.com"));
        vSeeds.push_back(CDNSSeedData("dyjykj.com", "dnsseed.dyjykj.com"));
        vSeeds.push_back(CDNSSeedData("coinwk.com", "dnsseed.coinwk.com"));
        vSeeds.push_back(CDNSSeedData("poolwk.com", "dnsseed.poolwk.com"));
        vSeeds.push_back(CDNSSeedData("znjjsc.com", "dnsseed.znjjsc.com"));
        vSeeds.push_back(CDNSSeedData("amxdns.com", "dnsseed.amxdns.com"));
	vSeeds.push_back(CDNSSeedData("smpool.com", "dnsseed.smpool.com"));
        vSeeds.push_back(CDNSSeedData("wxbkc.com", "dnsseed.wxbkc.com"));
	vSeeds.push_back(CDNSSeedData("ifcqd.com", "dnsseed.ifcqd.com"));
	vSeeds.push_back(CDNSSeedData("wwifc.com", "dnsseed.wwifc.com"));
	vSeeds.push_back(CDNSSeedData("hchccoin.com", "dnsseed.hchccoin.com"));
	vSeeds.push_back(CDNSSeedData("By5002.com", "dnsseed.By5002.com"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,102);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,230);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            (  9999, uint256S("0xd2f1a2f1b8862af96c5a750f3d99680ee96e7a4aac4e27f0587b1dbaa9b9207f"))
            ( 49999, uint256S("0xef2a0653071708d6a41dff2bb671bb459879f2c361a06024fca17a2566b41225"))
            ( 99979, uint256S("0xf376177d849c75c6344fc93c9429f59df7d5b25b067447e694e087bb765128e0"))
            (139999, uint256S("0xff9d5edf1661d8cd6fc53ffb9f583b16981874522044a760d8c8c004c312a41e"))
            (199999, uint256S("0xec62c7700fd83c56f2013b1b97a7dbcc2aad1f065176ea18d9c47701ced164d5"))
            (228800, uint256S("0x6a2a329c5d21d6433cf9bda5ba43d66a732898bcd0c81150f1584d095edd5cd5"))
            (242388, uint256S("0x4c2dfd22435525519e89041420f6692e709da34f48243cebe1be14d43adb1c5c"))
            (265420, uint256S("0x9ef4ce8e7dab5c2f2b9142ceb285419ef0ea62021e5f613d4a81a3fc9d53453e"))
	    (265497, uint256S("0x206aed8fb5b1ed94cf696bc5b964445380dd4c30c186e45ba5ed545866a242c7")) 
            (268559, uint256S("0xfd0ff0e0020f0ade68122c0fd82f648c7e6913e32cd6a3d8abc81694055daecc")) 
	    (268560, uint256S("0x08c5337322ea40d3602b98ab9d9b1d43abd87dda19a4f8e282414a838ae3dbb8"))
            (282045, uint256S("0x271abe1c26daf5a684034529befb217e16f87e1af779c0e63bdd971def3d8ba5"))
	    (380962, uint256S("0xa032a87b430091fbb4faa20f16c8247f93cfcc1854bd49a19c3c9fc3a0c43634"))
	    (453211, uint256S("0xea08eace1b78c5513d74750c7cfc01d0c1f3789fc650ccce197b85497405ce56"))
            (647000, uint256S("0x667fc19d6066d472176136f2a34dac9b2662e9d7212df3679e56042d8b198906"))
            (4333333, uint256S("0x8e4fcf3e003293882dec8943e42ed29e066cfc3782ff4d011c58c8b8ed9bb9a4"))
            (4368037, uint256S("0xb60d656dcc3fdd60b279a7de7ad8c21950c4cbae58698219785249e0174d4bcd"))
            (5781980, uint256S("0xa91e780de0b3f91f1b0515e56296b54804730cdfd21a45b4d2c433a3f92aebb7"))
            (6043693, uint256S("0x5518c133fead075e372027e69c2b245a01d5a6e95ef3c97d576bf42a62d1e6ef"))
	    (6887217, uint256S("0x58edc430d6ecc35ae3fa4d8ccdfb8a42752ff771d2a08c8e6dc1f1b3b6782d4d"))
	    (7081698, uint256S("0x4342f79249ffe1c4afe08fca143ee9945579528a9047afc0e79ef276ea6fde6b")),
            1617855646, // * UNIX timestamp of last checkpoint block
            8322858,   // * total number of transactions between genesis and last checkpoint
                        //   (the tx=... number in the SetBestChain debug.log lines)
            0.1125     // * estimated number of transactions per day after checkpoint
        };
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 210000;
        consensus.nMajorityEnforceBlockUpgrade = 51;
        consensus.nMajorityRejectBlockOutdated = 75;
        consensus.nMajorityWindow = 100;
        consensus.BIP34Height = 21111;
        consensus.BIP34Hash = uint256S("0x0000000023b3a96d3484e5abb3755c413e7d41500f8e2a5c3f0dd01299cd8ef8");
        consensus.powLimit = uint256S("00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 10 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = false;
        pchMessageStart[0] = 0x0b;
        pchMessageStart[1] = 0x11;
        pchMessageStart[2] = 0x09;
        pchMessageStart[3] = 0x07;
        vAlertPubKey = ParseHex("04302390343f91cc401d56d68b123028bf52e5fca1939df127f63c6467cdf9c8e2c14b61104cf817d0b780da337893ecc4aaff1309e536162dabbdb45200ca2b0a");
        nDefaultPort = 19321;
        nMaxTipAge = 0x7fffffff;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1296688602, 414098458, 0x1d00ffff, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        //assert(consensus.hashGenesisBlock == uint256S("0x000000000933ea01ad0ee984209779baaec3ced90fa3f408719526f8d77f4943"));
        //assert(genesis.hashMerkleRoot == uint256S("0x4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("bitcoin.petertodd.org", "testnet-seed.bitcoin.petertodd.org"));
        vSeeds.push_back(CDNSSeedData("bluematt.me", "testnet-seed.bluematt.me"));
        vSeeds.push_back(CDNSSeedData("bitcoin.schildbach.de", "testnet-seed.bitcoin.schildbach.de"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        checkpointData = (CCheckpointData) {
            boost::assign::map_list_of
            ( 546, uint256S("000000002a936ca763904c3c35fce2f3556c559c0214345d31b1bcebf76acb70")),
            1337966069,
            1488,
            300
        };

    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.nMajorityEnforceBlockUpgrade = 750;
        consensus.nMajorityRejectBlockOutdated = 950;
        consensus.nMajorityWindow = 1000;
        consensus.BIP34Height = -1; // BIP34 has not necessarily activated on regtest
        consensus.BIP34Hash = uint256();
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 10 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nMaxTipAge = 24 * 60 * 60;
        nDefaultPort = 18444;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1296688602, 2, 0x207fffff, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        //assert(consensus.hashGenesisBlock == uint256S("0x0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206"));
        //assert(genesis.hashMerkleRoot == uint256S("0x4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        checkpointData = (CCheckpointData){
            boost::assign::map_list_of
            ( 0, uint256S("0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206")),
            0,
            0,
            0
        };
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
    }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
            return mainParams;
    else if (chain == CBaseChainParams::TESTNET)
            return testNetParams;
    else if (chain == CBaseChainParams::REGTEST)
            return regTestParams;
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
