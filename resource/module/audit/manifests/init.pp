class audit {

	service {
		"auditd":
                name => $operatingsystem ? {
                        default => "auditd"
                        },
		enable    => "true",
		ensure    => "running"
	}

        package {
                "audit":
                name => $operatingsystem ? {
                        default => "audit"
                        },
                ensure => present
        }
	
}
