#ifndef __CONFIG_DEFINE_H__
#define __CONFIG_DEFINE_H__

enum ETaskEvent
{
	TE_NONE = 0,
	TE_PASS_MAIN_COPY, //Challenge main line
};


enum ETaskStatue
{
	TASK_UNFINISHED = 0, //! Unfinished
	TASK_FINISHED, //! Finished
	TASK_ONGOING //! Received
};


#endif //__CONFIG_DEFINE_H__