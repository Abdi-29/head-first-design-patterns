setChanged()
{
	changed = true
}

notifyObservers(Object arg)
{
	if (changed)
	{
		for every observer on the list
		{
			call update (this, arg)
		}
		changed = false
	}
}

notifyObservers()
{
	notifyObservers(null)
}
