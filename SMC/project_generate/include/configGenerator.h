
#ifndef _CONFIGGENERATOR_H_
#define _CONFIGGENERATOR_H_

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
typedef unsigned int uint;

class configGenerator
{
    friend class projectGenerator;
private:
    class ConfigPair
    {
        friend class configGenerator;
        friend class projectGenerator;
    private:
        string m_sOption;
        string m_sPrefix;
        string m_sValue;
        bool m_bLock;

        ConfigPair( const string & sOption, const string & sPrefix, const string & sValue ) : 
            m_sOption( sOption ), 
            m_sPrefix( sPrefix ), 
            m_sValue( sValue ), 
            m_bLock( false ) {}
    };
    typedef vector<ConfigPair> ValuesList;
    typedef map<string,string> DefaultValuesList;
    typedef map<string,bool> DependencyList;
    typedef map<string,vector<string>> OptimisedConfigList;

    ValuesList m_vFixedConfigValues;
    ValuesList m_vConfigValues;
    uint m_uiConfigValuesEnd;
    string m_sConfigureFile;
    string m_sToolchain;
    bool m_bLibav;
    string m_sProjectName;

    const string m_sWhiteSpace;


public:
    configGenerator( );

    bool passConfig( );

    bool passConfigFile( const string & stConfigFile );

    bool changeConfig( const string & stOption );

    bool outputConfig( );

private:
    void buildFixedValues( DefaultValuesList & mFixedValues );

    void buildReplaceValues( DefaultValuesList & mReplaceValues, DefaultValuesList & mASMReplaceValues );

    void buildReservedValues( vector<string> & vReservedItems );

    void buildAdditionalDependencies( DependencyList & mAdditionalDependencies );

    void buildOptimisedDisables( OptimisedConfigList & mOptimisedDisables );

    void buildForcedEnables( string sOptionLower, vector<string> & vForceEnable );

    void buildForcedDisables( string sOptionLower, vector<string> & vForceDisable );

    void buildObjects( const string & sTag, vector<string> & vObjects );



    bool getConfigList( const string & sList, vector<string> & vReturn, bool bForce=true, uint uiCurrentFilePos=string::npos );

    bool passFindThings( const string & sParam1, const string & sParam2, const string & sParam3, vector<string> & vReturn );

    bool passAddSuffix( const string & sParam1, const string & sParam2, vector<string> & vReturn, uint uiCurrentFilePos=string::npos );

    bool passFilterOut( const string & sParam1, const string & sParam2, vector<string> & vReturn, uint uiCurrentFilePos );

    bool passConfigList( const string & sPrefix, const string & sSuffix, const string & sList );

    bool buildDefaultValues( );

    bool fastToggleConfigValue( const string & sOption, bool bEnable );

    bool toggleConfigValue( const string & sOption, bool bEnable, bool bRecursive=false );
    
    ValuesList::iterator getConfigOption( const string & sOption );

    ValuesList::iterator getConfigOptionPrefixed( const string & sOption );

    bool passDependencyCheck( const ValuesList::iterator vitOption );
};

#endif