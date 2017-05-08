package options

// AddDefaultOptions adds internal options that can be set by the user through
// the command-line interface.
func (o *Options) AddDefaultOptions() {
	o.Add(NewStringOption("columns"))
	o.Add(NewStringOption("sort"))
}

// Defaults is the default, internal configuration file.
const Defaults string = `
# Global options
set columns=artist,track,title,album,year,time
set sort=file,track,disc,album,year,albumartistsort

# Song tag styles
style album teal
style allTagsMissing red
style artist yellow
style date green
style time darkmagenta
style title white bold
style track green
style year green

# Other styles
style commandText default
style currentSong black yellow
style cursor black white
style elapsed green
style errorText white red bold
style header green bold
style mostTagsMissing red
style noCurrentSong red
style readout default
style searchText white bold
style selection white blue
style sequenceText teal
style shortName blue bold
style statusbar default
style switches teal
style topbar blue bold
style version blue bold
style visualText teal
style volume green

# Keyboard bindings: cursor movement
bind <Up> cursor up
bind k cursor up
bind <Down> cursor down
bind j cursor down
bind <PgUp> cursor pgup
bind <PgDn> cursor pgdn
bind <Home> cursor home
bind gg cursor home
bind <End> cursor end
bind G cursor end
bind gc cursor current
bind R cursor random
bind b cursor prev-of album
bind e cursor next-of album

# Keyboard bindings: input mode
bind : inputmode input
bind / inputmode search
bind <F3> inputmode search
bind v inputmode visual
bind V inputmode visual

# Keyboard bindings: player and mixer
bind <Enter> play cursor
bind <Space> pause
bind s stop
bind h previous
bind l next
bind + volume +2
bind - volume -2
bind M volume mute

# Keyboard bindings: other
bind <C-c> quit
bind <C-l> redraw
bind <C-s> sort
bind i print file
bind t list next
bind T list previous
bind <C-d> list duplicate
bind <C-g> list remove
bind <C-j> isolate artist
bind <C-t> isolate albumartist,album
bind m select toggle
bind a add
bind <Delete> remove
bind x remove
`
