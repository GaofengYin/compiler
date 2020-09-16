class clamav {

	package { clamav:
		name => $operatingsystem ? {
			default	=> "clamav"
			},
		ensure => latest
	}

	package { clamav-db:
		name => $operatingsystem ? {
			default	=> "clamav-db"
			},
		ensure => latest
	}
}

class clamd inherits clamav {
	package { clamd:
		name => $operatingsystem ? {
			default	=> "clamd"
			},
		ensure => latest
	}

	service { "clamd":
		name => "clamd",
		ensure => true,
		enable => true,
		hasrestart => true,
		hasstatus => true,
		subscribe => [ Package["clamav"] ]
	}
}

