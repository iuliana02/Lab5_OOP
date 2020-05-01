#pragma once
#include "Repository.h"

class ControllerBenutzer : public Repository
{
private:
	// <summary>	The watchliste. </summary>
	//vector<Film> watchliste;
	Repository repo;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	ControllerBenutzer();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	~ControllerBenutzer();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	View by genre. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void view_by_genre();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes the film. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void remove_film();

	void show_watchliste();

};