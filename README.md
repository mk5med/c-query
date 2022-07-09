# c-query
An easy to learn library and language for querying data.

Use case:
```
$ ./ical -q 'cal(event(attendee))' sample.ical
$ ./ical -q 'cal(event(title, dtstrt, dtend, organiser, attendees))' sample.ical
{
  calendar: {
    events: [
      {
        title: "Event 200",
        dtstrt: 2001,
        dtend: 2077,
        organiser: "Bob",
        attendees: [
          "mailto:p2p@push.com"
        ]
      }
    ]
  }
}
$ ./ical -q 'cal(event(title="Event 201", dtstrt, dtend, organiser, attendees))'
{
  calendar: {
    events: []
  }
}
```

## Syntax
`attribute(attribute=constraint, ...attribute)`