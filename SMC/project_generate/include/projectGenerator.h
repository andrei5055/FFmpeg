
#ifndef _PROJECTGENERATOR_H_
#define _PROJECTGENERATOR_H_

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include <Windows.h>

#include "configGenerator.h"

class projectGenerator
{
private:
    typedef vector<string> StaticList;
    typedef map<string,StaticList> UnknownList;
    ifstream        m_ifInputFile;
    string          m_sInLine;
    StaticList      m_vIncludes;
    StaticList      m_vCPPIncludes;
    StaticList      m_vCIncludes;
    StaticList      m_vYASMIncludes;
    StaticList      m_vHIncludes;
    StaticList      m_vLibs;
    UnknownList     m_mUnknowns;
    string          m_sProjectDir;

    map<string,StaticList> m_mProjectLibs;

public:

    configGenerator m_ConfigHelper;

    bool passAllMake( );

private:

    bool outputProject( );

    bool outputSolution();

    bool passStaticIncludeObject( uint & uiStartPos, uint & uiEndPos, StaticList & vStaticIncludes );

    bool passStaticIncludeLine( uint uiStartPos, StaticList & vStaticIncludes );

    bool passStaticInclude( uint uiILength, StaticList & vStaticIncludes );

    bool passDynamicIncludeObject( uint & uiStartPos, uint & uiEndPos, const string & sIdent, StaticList & vIncludes );

    bool passDynamicIncludeLine( uint uiStartPos, const string & sIdent, StaticList & vIncludes );

    bool passDynamicInclude( uint uiILength, StaticList & vIncludes );

    bool passCInclude( );

    bool passDCInclude( );

    bool passYASMInclude( );

    bool passDYASMInclude( );

    bool passMMXInclude( );

    bool passDMMXInclude( );

    bool passHInclude( );

    bool passDHInclude( );

    bool passLibInclude( );

    bool passDLibInclude( );

    bool passDUnknown( );

    bool passDLibUnknown( );

    bool passMake( );

    static bool findFile( const string & sFileName, string & sRetFileName );

    static bool findFiles( const string & sFileSearch, vector<string> & VRetFiles );

    bool findSourceFile( const string & sFile, const string & sExtension, string & sRetFileName );

    void buildInterDependenciesHelper( const StaticList & vConfigOptions, const StaticList & vAddDeps, StaticList & vLibs );

    void buildInterDependencies( const string & sProjectName, StaticList & vLibs );

    void buildDependencies( const string & sProjectName, StaticList & vLibs, StaticList & vAddLibs, StaticList & vIncludeDirs, StaticList & vLib32Dirs, StaticList & vLib64Dirs );

    void buildProjectDependencies( const string & sProjectName, map<string,bool> & mProjectDeps );

    void buildProgramIncludes( const string & sProject, StaticList & vCIncludes, StaticList & vHIncludes, StaticList & vLibs, StaticList & vIncDirs, StaticList & vLib32Dirs, StaticList & vLib64Dirs );

    void buildProjectGUIDs( map<string, string> & mLibKeys, map<string, string> & mProgramKeys );

    bool copyFile( const string & sSourceFile, const string & sDestinationFile );

    void deleteFile( const string & sDestinationFile );
};

#endif
