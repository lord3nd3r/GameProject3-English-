#ifndef __WEB_ACTION_DEFINE_H__
#define __WEB_ACTION_DEFINE_H__

enum EWebAction
{
    EWA_NONE = 0,               // Invalid action
    EWA_SEAL_ACCOUNT,           // Seal/unseal account
    EWA_SEAL_ROLE,              // Ban role
    EWA_SERVER_CHNAGE,          // Server configuration changed
    EWA_REVIEW_CHANGE,          // Review information changed
    EWA_RELOAD_TABLE,           // Reload configuration tables
    EWA_SINGLE_MAIL,            // Send single mail
    EWA_GROUP_MAIL,             // Send group mail
    EWA_OPEN_SVR_TIME,          // Modify server open time
    EWA_SERVER_START,           // Start server
    EWA_SERVER_STOP,            // Stop server
    EWA_SERVER_UPDATE,          // Update server
    EWA_SERVER_INFO,            // Server information
    EWA_GM_COMMAND,             // Execute GM command
    EWA_KICKOFF_PLAYER,         // Kick player offline
    EWA_PAY_CALLBACK,           // Payment callback notification
    EWA_DELTE_MAIL,             // Delete mail
    EWA_NOTICE_POPUP,           // In-game popup notice
    EWA_ACTIVITY_CHANGE,        // Activity control update
    EWA_DELETE_ROLE,            // Delete role
    EWA_REMOVE_ITEM,            // Remove role item
    EWA_MERGE_CHANGE,           // Merge-server configuration change
    EWA_GAMEPARAM_CHANGE,       // Game parameters changed
};


enum EWebResult
{
    EWR_SUCCESSED = 0,          // Success
    EWR_FAILURE,                // Failure
    EWR_INVALID_ACT,            // Invalid action
};


#endif //__WEB_ACTION_DEFINE_H__